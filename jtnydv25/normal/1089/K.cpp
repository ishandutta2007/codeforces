#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 1000001;
const int BSZ = 400;
vector<pair<LL, LL > > st;
LL B[N], tot[N / BSZ + 1];
int T[N], Q[N];
LL cache[N];
int correctCache = -1;

void insert(LL l, LL r) {
  while(st.size() && st.back().FF <= r) {
    r += st.back().SS - st.back().FF;
    st.pop_back();
  }
  st.pb(mp(l, r));
}

// Re-compute block which contains idx
void recompute(int idx) {
  int b = idx / BSZ;
  int s = b * BSZ;
  int e = s + BSZ - 1;
  int sm = 0;
  st.clear();
  correctCache = min(correctCache, b - 1);
  for(int i = e; i >= s; i--) if(T[i]) {
    sm += T[i];
    LL l = i, r = i + T[i];
    insert(l, r);
  }
  rep(i,s,e+1) {
    if(!st.size()) {
      B[i] = 0;
      continue;
    }
    B[i] = st[0].SS;
    if(st.back().FF == i) {
      LL l = st.back().FF;
      LL r = st.back().SS;
      l++; r++;
      st.pop_back();
      insert(l, r);
    }
  }
  tot[b] = sm;
}

LL query(int idx) {
  int b = idx / BSZ;
  int s = b * BSZ;
  int e = idx;
  st.clear();
  for(int i = e; i >= s; i--) if(T[i]) {
    LL l = i, r = i + T[i];
    insert(l, r);
  }

  LL val = 0;
  if(correctCache != -1 && b > 0) {
    val = cache[min(correctCache, b - 1)];
  }
  rep(i,correctCache+1,b) {
    int curs = i * BSZ;
    int cure = i * BSZ + BSZ - 1;
    if(val > cure) {
      val += tot[i];
    } else if(val < curs) {
      val = max(val, B[curs]);
    } else {
      val = max(val, B[val]);
    }
    cache[i] = val;
    correctCache = i;
  }
  // cout << val << "\n";
  if(val) {
    insert(0, val);
  }
  if(!st.size() || st[0].SS < idx) {
    return 0;
  }
  return st[0].SS - idx;
}

int main() {
  int q;
  S(q);
  rep(i,1,q+1) {
    getchar();
    char c = getchar();
    if(c == '+') {
      int s,t;
      S2(s,t);
      s--;
      Q[i] = s;
      T[s] = t;
      recompute(s);
    } else if(c == '-') {
      int idx;
      S(idx);
      int s = Q[idx];
      T[s] = 0;
      recompute(s);
    } else {
      int s;
      S(s);
      s--;
      LL ans = query(s);
      printf("%lld\n",ans);
    }
  }
  return 0;
}