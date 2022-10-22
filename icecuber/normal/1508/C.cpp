#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 650;
int par[nax], sz[nax];
int Find(int p) {
  return p == par[p] ? p : (par[p] = Find(par[p]));
}

void join(int a, int b) {
  assert(a == par[a]);
  assert(b == par[b]);
  assert(a != b);
  if (sz[a] > sz[b]) swap(a,b);
  par[a] = b;
  sz[b] += sz[a];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<array<int,3>> edge;
  map<array<int,2>, int> ma;
  int all_xor = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edge.push_back({c,a,b});
    ma[{a,b}] = ma[{b,a}] = c;
    all_xor ^= c;
  }

  ll all0 = 0;
  {
    //All non-edges 0
    priority_queue<array<int,2>> pq;
    pq.push({0,0});
    set<int> left;
    for (int i = 1; i < n; i++) left.insert(i);
    vector<int> done(n);
    while (pq.size()) {
      auto [nw,p] = pq.top();
      pq.pop();
      if (done[p]++) continue;
      all0 += -nw;
      vector<int> toerase;
      for (int i : left) {
        auto it = ma.find({p,i});
        if (it == ma.end()) {
          pq.push({0,i});
          toerase.push_back(i);
        } else {
          pq.push({-it->second, i});
        }
      }
      for (int i : toerase) left.erase(i);
    }
  }

  if ((ll)n*(n-1)/2-m > n-1) {
    cout << all0 << endl;
  } else {
    assert(n < 650);

    ll ans = all0+all_xor;

    if (n == 2) {
      cout << 0 << endl;
      return 0;
    }

    sort(edge.begin(), edge.end());
    vector<array<int,2>> nonedge;
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < i; j++)
        if (!ma.count({i,j}))
          nonedge.push_back({i,j});

    assert((int)nonedge.size() < n);
    for (int ri = 0; ri < (int)nonedge.size(); ri++) {
      for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
      ll cost = 0;
      for (int i = 0; i < (int)nonedge.size(); i++) {
        if (i == ri) continue;
        auto [a,b] = nonedge[i];
        a = Find(a);
        b = Find(b);
        if (a != b) join(a,b);
      }
      for (auto [c,a,b] : edge) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
          join(a,b);
          cost += c;
        }
      }
      for (int i = 0; i < n; i++) assert(Find(i) == Find(0));
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
}