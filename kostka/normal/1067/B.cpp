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

const int MAXN = 100007;
vector <int> G[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue <int> Q;
  vi war(n, 1e9), ttt(n);
  for(int i=0; i<n; i++) {
    if(SZ(G[i]) == 1) {
      Q.push(i);
      war[i] = 0;
    }
  }

  while(!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for(auto w : G[v]) {
      if(war[w] == war[v]+1) ttt[w]++;
      if(war[w] > war[v] + 1) {
        war[w] = war[v] + 1;
        if(war[w] > k) {
          cout << "No\n";
          return 0;
        }
        Q.push(w);
        ttt[w]++;
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(auto j : G[i]) if(war[i] == war[j]) {
      cout << "No\n";
      return 0;
    }
    if(war[i] and ttt[i] < 3) {
      cout << "No\n";
      return 0;
    }
  }
  int ret = 0;
  for(int i=0; i<n; i++) ret += (war[i] == k);
  cout << ((ret == 1) ? "Yes\n" : "No\n");
  return 0;
}