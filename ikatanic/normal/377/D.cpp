#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> par;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 1<<19;
const int inf = 1e9;

const int offset = 1<<19;

struct Tournament {
  int T[2*MAXN];
  int S[2*MAXN];
  int K[2*MAXN];
  
  void init() {
    for (int i = 0; i < 2*offset; ++i)
      T[i] = -inf, S[i] = 0;
  }

  void propagate(int i) {
    int l = i*2, r = l+1;
    if (S[i]) {
      S[l] += S[i], S[r] += S[i];
      T[l] += S[i], T[r] += S[i];
      S[i] = 0;
    }
  }

  void merge(int i) {
    int l = i*2, r = l+1;
    if (T[l] > T[r]) T[i] = T[l] + S[i], K[i] = K[l]; else
      T[i] = T[r] + S[i], K[i] = K[r];
  }

  void add(int i, int lo, int hi, int a, int b, int k) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) { S[i] += k; T[i] += k; return; }
    propagate(i);

    add(i*2, lo, (lo+hi)/2, a, b, k);
    add(i*2+1, (lo+hi)/2, hi, a, b, k);

    merge(i);
  }
 
  void set(int x, int v) {
    x += offset;
    T[x] = v, S[x] = 0;
    K[x] = x-offset;
    

    for (int y = x/2; y; y /= 2)
      T[x] -= S[y];
    
    for (x /= 2; x; x /= 2)
      merge(x);
  }

  par get(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return make_pair(-inf, 0);
    if (lo >= a && hi <= b) return make_pair(T[i], K[i]);
    propagate(i);
    return max(get(i*2, lo, (lo+hi)/2, a, b), get(i*2+1, (lo+hi)/2, hi, a, b));
  }

  void add(int a, int b, int k) {
    add(1, 0, offset, a, b, k);
  }
  
  par getmax(int a, int b) {
    return get(1, 0, offset, a, b);
  }
} T;

struct Loga {
  int L[MAXN];
  
  void add(int x, int y) {
    for (++x; x < MAXN; x += x&-x)
      L[x] += y;
  }

  int sum(int x) {
    x = min(x, MAXN-2);
    int ans = 0;
    for (++x; x; x -= x&-x)
      ans += L[x];
    return ans;
  }

  int sum(int x, int y) {
    return sum(y) - sum(x-1);
  }
} countR, countV;

int l[MAXN], v[MAXN], r[MAXN];
int cnt[MAXN];
vector<int> vl[MAXN], vv[MAXN];

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d %d", l+i, v+i, r+i);
    vl[l[i]].push_back(i);
    vv[v[i]].push_back(i);
  }

  T.init();

  int ans = 0, lo, hi;
  for (int p = 0; p < MAXN; ++p) {
    
    for (int i: vl[p]) {
      int L = l[i], R = r[i], V = v[i];
      if (cnt[R] == 0) T.set(R, countV.sum(L, R) - countR.sum(0, R-1));
      cnt[R]++;

      T.add(R+1, MAXN, -1);
      T.add(V, MAXN, +1);
      
      countV.add(V, +1);
      countR.add(R, +1);
      
      par r = T.getmax(L, MAXN);
      if (r.first > ans) ans = r.first, lo = p, hi = r.second;
    }

    for (int i: vv[p]) {
      int L = l[i], R = r[i], V = v[i];
      if (cnt[R] == 1) T.set(R, -inf);
      cnt[R]--;
    
      T.add(R+1, MAXN, +1);
      T.add(V, MAXN, -1);
      
      countV.add(V, -1);
      countR.add(R, -1);
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < n; ++i)
    if (l[i] <= lo && r[i] >= hi && v[i] >= lo && v[i] <= hi) printf("%d ", i+1);
  printf("\n");
  return 0;
}