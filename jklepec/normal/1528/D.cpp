#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef pair<int, int> pii;

const int MAXN = 605;
vector<pii> e[MAXN];

const int inf = 2e9 + 5;

int n;
int modan(int x) {
  x %= n;
  if (x < 0) return x + n;
  return x;
}

void solve() {
  cin >> n;
  int m; cin >> m;

  REP(i, m) {
    int a, b, c; cin >> a >> b >> c;

    e[a].pb({b, c});
  }

  vector<bool> bio(n);
  vector<int> dist(n);
  vector<int> leti(n);

  REP(u, n) {

    REP(i, n) bio[i] = false;
    REP(i, n) dist[i] = inf;

    dist[u] = 0;

    int x = u;
    REP(tt, n - 1) {
      bio[x] = true;

      REP(i, n) leti[i] = inf;
      for (auto pp: e[x]) {
        leti[modan(pp.fi + dist[x])] = pp.se;
      }

      pii mini = pii(inf, -1);
      REP(i, n) {
        if (leti[i] < mini.fi) mini = {leti[i], i};
      }

      int pocetni = mini.se;
      mini = {inf, -1};
      REP(i, n) {
        leti[pocetni] = min(leti[pocetni], leti[modan(pocetni - 1)] + 1);
        dist[pocetni] = min(dist[pocetni], dist[x] + leti[pocetni]);
        if(!bio[pocetni]) if(dist[pocetni] < mini.fi) mini = {dist[pocetni], pocetni};

        pocetni = modan(pocetni + 1);
      }

      x = mini.se;

    }

    REP(i, n) cout << dist[i] << " ";
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tt = 1;
  while(tt--) solve();
}