#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int INF = 2e9;
const int M = 1400;
const int N = 5e4 + 10;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int n, s, x, id[N + 5], val[N + 5], nxt[N + 5];
bool vis[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> s >> x;
  if(n <= 2000) {
    int z = INF, v, nxt;
    rep(i, 1, n) {
      cout << "? " << i << endl;
      cin >> v >> nxt;
      if(v >= x) z = min(z, v);
    }
    if(z == INF) z = -1;
    cout << "! " << z << endl;
    return 0;
  }
  uniform_int_distribution<int> ran(1, n);
  rep(i, 1, M) {
    if(i == 1) id[1] = s;
    else {
      while(1) {
        id[i] = ran(rnd);
        if(!vis[id[i]]) break ;
      }
    }
    vis[id[i]] = 1;
    cout << "? " << id[i] << endl;
    cin >> val[id[i]] >> nxt[id[i]];
  }
  int z = INF;
  sort(id + 1, id + M + 1, [&](int x, int y) { return val[x] < val[y]; });
  if(val[s] >= x) z = val[s];
  id[M + 1] = -1;
  rep(i, 1, M) {
    if(val[id[i]] < x && (i == M || val[id[i + 1]] >= x)) {
      if(i < M) z = min(z, val[id[i + 1]]);
      for(int j = nxt[id[i]]; j != id[i + 1]; j = nxt[j]) {
        cout << "? " << j << endl;
        cin >> val[j] >> nxt[j];
        if(val[j] >= x) z = min(z, val[j]);
      }
      break ;
    }
  }
  if(z == INF) z = -1;
  cout << "! " << z << endl;
  return 0;
}