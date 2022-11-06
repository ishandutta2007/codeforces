#include <bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;

int n, tot[N], cnt[N];
vector<int> g[N];

void dfs(int x, int fa) {
  tot[x] = 1;
  for(auto y : g[x]) if(y ^ fa){
      dfs(y, x), tot[x] += tot[y];
    }
}

int findrt(int x, int fa) {
  for(auto y : g[x]) if(y ^ fa) {
      if(tot[y] > n / 2) return findrt(y, x);
    }
  return x;
}

void solve() {
  cin >> n;
  fo(i, 2, n) {
    int fa; cin >> fa;
    g[i].emplace_back(fa);
    g[fa].emplace_back(i);
  }
  dfs(1, 0);
  int rt = findrt(1, 0);
  dfs(rt, 0);
  bitset<1000001> s; s.set(0);
  for(auto u : g[rt]) cnt[tot[u]]++;
  fo(i, 1, n) if(cnt[i]) {
    for(int t = 1; t <= cnt[i]; t <<= 1) {
      s |= (s << (t * i));
      cnt[i] -= t;
    }
    if(cnt[i]) s |= (s << (cnt[i] * i));
  }
  LL sum = 0, mx = 0;
  fo(i, 0, n) {
    if(s[i]) mx = max((LL)i * (n - 1 - i), mx);
    sum += tot[i];
  }
  cout << mx + sum << '\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}