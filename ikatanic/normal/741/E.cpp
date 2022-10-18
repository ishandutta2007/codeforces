#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 201000;
const int B = 300;

struct STrmq {
  vector<vector<int>> table;
  vector<int> logs, array;

  STrmq(const vector<int>& a) {
    if (a.size() == 0) return;

    array = a;
    int lg = 0;
    while ((1<<lg) <= (int)a.size()) lg++;
    table = vector<vector<int>>(a.size(), vector<int>(lg));

    REP(i, (int)a.size()) table[i][0] = i;
    FOR(j, 1, lg) REP(i, (int)a.size()) {
      if (i + (1<<(j-1)) < (int)a.size() && a[ table[i+(1<<(j-1))][j-1] ] < a[ table[i][j-1] ]) {
        table[i][j] = table[i+(1<<(j-1))][j-1];
      } else {
        table[i][j] = table[i][j-1];
      }
    }

    logs.resize(a.size() + 1);
    logs[0] = 0;
    FOR(i, 1, (int)a.size() + 1)
      logs[i] = logs[i - 1] + (i == (1 << (logs[i-1]+1)));
  }

  int query(int a, int b) {
    int k = logs[b - a + 1];
    if (array[table[a][k]] <= array[table[b-(1<<k)+1][k]]) {
      return table[a][k];
    } else {
      return table[b-(1<<k)+1][k];
    }
  }
};

vector<int> RMQ(const vector<int>& array, const vector<pair<int, int>>& queries) {
  int n = array.size();
  vector<int> dad(n);
  function<int (int)> findset = [&] (int x) {
    return x == dad[x] ? x : dad[x] = findset(dad[x]);
  };
 
  vector<vector<int>> qs(n);
  REP(i, (int)queries.size()) qs[queries[i].second].push_back(i);

  vector<int> ans(queries.size());
  vector<int> stack;
  REP(i, n) {
    dad[i] = i;
    while (stack.size() && array[stack.back()] > array[i]) {
      dad[stack.back()] = i;
      stack.pop_back();
    }
    stack.push_back(i);
    for (int qi: qs[i]) ans[qi] = findset(queries[qi].first);
  }
  
  return ans;
}

namespace SuffixArray {
  const int MAXN = 200020;

  int lcp[MAXN], A[MAXN];
  
  void build(char *s, int n) {
    static int tmp[MAXN], bc[MAXN];
    REP(i, n) A[i] = i, bc[i] = s[i];

    for (int T = 1; ; T *= 2) {
      auto cmp = [&s, &T, &n] (const int &a, const int &b) {
	if (bc[a] != bc[b]) return bc[a] < bc[b];
	if (a+T >= n || b+T >= n) return a > b;
	return bc[a+T] < bc[b+T];
      };
      sort(A, A + n, cmp);
      tmp[A[0]] = 0;
      FOR(i, 1, n) tmp[A[i]] = tmp[A[i-1]] + cmp(A[i-1], A[i]);
      REP(i, n) bc[i] = tmp[i];
      if (bc[A[n-1]] == n-1) break;
    }

    lcp[0] = 0;
    int h = 0;
    REP(i, n)
      if (bc[i] > 0) {
	int j = A[ bc[i]-1 ];
	while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
	lcp[bc[i]] = h;
	if (h > 0) --h;
      }
  }
};

char s[MAX];
char t[MAX];
char a[MAX];

int slen, tlen;

int main(void) {
  int q;
  scanf("%s %s %d", s, t, &q);
  slen = strlen(s);
  tlen = strlen(t);

  REP(i, slen) a[i] = s[i];
  REP(i, tlen) a[slen + i] = t[i];

  SuffixArray::build(a, slen + tlen);
  int* A = SuffixArray::A;
  int* lcp = SuffixArray::lcp;
  vector<int> invA(slen + tlen);
  REP(i, slen + tlen) invA[A[i]] = i;
  
  STrmq lcp_rmq(vector<int>(lcp, lcp + slen + tlen));
  auto get_lcp = [&] (int i, int j) {
    assert(i < slen + tlen && j < slen + tlen);
    if (i == j) return slen + tlen - i;
    i = invA[i], j = invA[j];
    if (i > j) swap(i, j);
    return lcp[lcp_rmq.query(i + 1, j)];
  };

  vector<int> v;
  REP(i, slen + 1) v.push_back(i);

  sort(v.begin(), v.end(), [&] (int x, int y) {
      int l;
      bool flip = false;
      if (x < y) swap(x, y), flip = true;
      if (x-y >= tlen) {
        if ((l = get_lcp(y, slen)) < tlen) return (a[y+l] < a[slen+l]) ^ flip;
        if ((l = get_lcp(y+tlen, y)) < x-y-tlen) return (a[y+tlen+l] < a[y+l]) ^ flip;
        if ((l = get_lcp(slen, x-tlen)) < tlen) return (a[slen+l] < a[x-tlen+l]) ^ flip;
      } else {
        if ((l = get_lcp(y, slen)) < x-y) return (a[y+l] < a[slen+l]) ^ flip;
        if ((l = get_lcp(slen, slen+x-y)) < tlen-(x-y)) return (a[slen+l] < a[slen+x-y+l]) ^ flip;
        if ((l = get_lcp(slen+tlen-(x-y), y)) < (x-y)) return (a[slen+tlen-(x-y)+l] < a[y+l]) ^ flip;
      }
      return (x < y) ^ flip;
    }
  );

  int n = slen + 1;
  vector<int> a(n);
  REP(i, n) a[v[i]] = i;
  
  STrmq rmq(a);

  vector<pair<int, int>> ans(q);
  vector<int> ql(q), qr(q), qk(q), qx(q), qy(q);
  vector<vector<int>> qs(B);

  REP(i, q) {
    scanf("%d %d %d %d %d", &ql[i], &qr[i], &qk[i], &qx[i], &qy[i]);
    
    ans[i] = {n, -1};
    
    if (qk[i] < B) {
      qs[qk[i]].push_back(i);
    } else {
      int x = qx[i], y = qy[i];
      while (x < n) {
        int l = max(ql[i], x);
        int r = min(qr[i], y);
        if (l <= r) {
          int best = rmq.query(l, r);
          ans[i] = min(ans[i], {a[best], best});
        }
        x += qk[i], y += qk[i];
      }
    }
  }
    
  FOR(k, 1, B) {
    REP(i, k) {
      vector<int> v;
      for (int j = i; j < n; j += k)
        v.push_back(a[j]);

      vector<pair<int, int>> queries;
      vector<int> queries_id;
      
      for (int qi: qs[k]) {
        if (qx[qi] <= i && i <= qy[qi] && qr[qi] >= i) {
          int l = (ql[qi]-i+k-1) / k;
          int r = (qr[qi]-i) / k;
          if (l <= r) {
            queries.push_back({l, r});
            queries_id.push_back(qi);
          }
        }
      }

      if (v.size() && queries.size()) {
        vector<int> mins = RMQ(v, queries);
        REP(j, (int)mins.size()) {
          int qi = queries_id[j];
          int best = mins[j]*k + i;
          ans[qi] = min(ans[qi], {a[best], best});
        }
      }
    }
  }
  
  REP(i, q) printf("%d ", ans[i].second);
  printf("\n");

  return 0;
}