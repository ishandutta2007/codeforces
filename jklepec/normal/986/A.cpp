#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5;

vector<int> a[MAXN];

int bio[MAXN];
vector<int> dist[MAXN], e[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m, s, k; cin >> n >> m >> k >> s;
  REP(i, n) {
    int x; cin >> x;
    a[x - 1].push_back(i);
  }

  REP(i, m) {
    int x, y;
    cin >> x >> y;
    x --; y --;
    e[x].pb(y);
    e[y].pb(x);
  }

  REP(i, k) {
    int C = i + 1;

    queue<point> Q;
    for(auto ind: a[i]) {
      Q.push({0, ind});
      bio[ind] = C;
    }

    while(Q.size()) {
      int d = Q.front().first;
      int ind = Q.front().second;
      Q.pop();
      dist[ind].pb(d);

      for(auto j: e[ind]) {
        if(bio[j] != C) {
          bio[j] = C;
          Q.push({d + 1, j});
        }
      }
    }
  }

  REP(i, n) {
    ll sum = 0;
    sort(dist[i].begin(), dist[i].end());
    REP(j, s) {
      sum += dist[i][j];
    }
    cout << sum << " ";
  }
}