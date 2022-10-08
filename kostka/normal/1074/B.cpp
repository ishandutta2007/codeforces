//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 1007;
vi G[MAXN];
bool odw[MAXN];
bool chosen[2][MAXN];

int bfs(int v) {
  odw[v] = true;
  queue <int> Q;
  Q.push(v);
  while(!Q.empty()) {
    int w = Q.front();
    Q.pop();
    if(chosen[0][w]) return w;
    for(auto x : G[w]) {
      if(!odw[x]) {
        odw[x] = true;
        Q.push(x);
      }
    }
  }
  return -1;
}

void test() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    G[i].clear();
    odw[i] = chosen[0][i] = chosen[1][i] = 0;
  }
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vi X[2];
  for(int d=0; d<2; d++) {
    int x;
    cin >> x;
    for(int i=0; i<x; i++) {
      int a;
      cin >> a;
      X[d].push_back(a);
      chosen[d][a] = true;
    }
  }
  cout << "B " << X[1][0] << endl;
  int root;
  cin >> root;
  int closest = bfs(root);
  cout << "A " << closest << endl;
  int res;
  cin >> res;
  cout << "C " << (chosen[1][res] ? closest : -1) << endl;
}


int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) test();
  return 0;
}