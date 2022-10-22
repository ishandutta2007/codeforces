#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> node[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].emplace_back(b, 1);
    node[b].emplace_back(a, 1<<20);
  }

  array<int,2> ans = {1<<30,1<<30};

  priority_queue<array<int,3>, vector<array<int,3>>,greater<array<int,3>>> pq;

  vector<vector<array<int,2>>> dist(2, vector<array<int,2>>(n, {1<<30,1<<30}));
  vector<vector<array<int,2>>> pref(20, vector<array<int,2>>(n, {1<<30,1<<30}));

  dist[0][0] = {0,0};
  pq.push({0,0,0});

  auto myless =
    [&](array<int,2> A, array<int,2> B) {
      if (A[0] >= 20) {
        if (B[0] < 20) return 0;
        return int(A < B);
      } else {
        if (B[0] >= 20) return 1;
        return int((1<<A[0])-1+A[1] < (1<<B[0])-1+B[1]);
      }
    };
  auto add = [&](int nt, int nd, int np) {
               if (nt < 20) {
                 auto&D = pref[nt][np];
                 if (myless({nt,nd},D)) {
                   D = {nt,nd};
                   pq.push({nt,nd,np});
                 }
               } else {
                 auto&D = dist[nt%2][np];
                 array<int,2> dd = {nt,nd};
                 if (dd < D) {
                   D = dd;
                   pq.push({nt,nd,np});
                 }
               }
             };

  while (pq.size()) {
    auto [t,d,p] = pq.top();
    pq.pop();

    if (t < 20) {
      if (myless(pref[t][p], {t,d})) continue;
    } else {
      if (array<int,2>{t,d} > dist[t%2][p]) continue;
    }

    if (p == n-1) {
      if (ans[0] >= 20) {
        ans = min(array<int,2>{t,d}, ans);
      } else {
        if ((1<<t)-1 + d < (1<<ans[0])-1 + ans[1])
          ans = {t,d};
      }
    }

    add(t+1,d,p);

    for (auto [i,c] : node[p]) {
      if ((c == 1<<20) == t%2) {
        add(t,d+1,i);
      }
    }
  }

  const ll mod = 998244353;
  ll p2 = 1;
  for (int i = 0; i < ans[0]; i++) {
    p2 = p2*2%mod;
  }
  cout << (ans[1]+p2+mod-1)%mod << endl;
  return 0;
}