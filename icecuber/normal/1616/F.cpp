#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef map<int,int> EQ;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<int> ans(m+1, 1);
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      adj[a][b] = adj[b][a] = i;
      ans[i] = c%3;
    }
    vector<EQ> eq;
    map<int,set<int>> todo;
    vector<set<int>> node(m+1);
    for (int i = 0; i < n; i++) { 
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < j; k++) {
          if (!!adj[i][j]+!!adj[i][k]+!!adj[j][k] == 3) {
            EQ e;
            for (int l : {adj[i][j], adj[i][k], adj[j][k]}) {
              e[l] = 1;
              node[l].insert(eq.size());
            }
            todo[3].insert(eq.size());
            eq.push_back(e);
          }
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (ans[i] != -1) {
        EQ e;
        e[i] = 2;
        e[0] = ans[i];
        todo[1].insert(eq.size());
        node[i].insert(eq.size());
        eq.push_back(e);
        ans[i] = -1;
      }
    }

    auto Insert = [&](EQ a, EQ b) {
      int l = a.rbegin()->first;
      assert(l && a[l]);
      int f = ((-b[l] * a[l])%3+3)%3;
      vector<int> rem;
      for (auto [i,w] : a) {
        (b[i] += w*f) %= 3;
        if (!b[i]) rem.push_back(i);
      }
      for (int i : rem) b.erase(i);
      return b;
    };
    auto Sz = [&](int j) {
      return (int)eq[j].size() - (int)eq[j].count(0);
    };

    auto Print = [&]() {
      for (EQ e : eq) {
        int notfirst = 0;
        for (auto [i,w] : e) {
          if (!i) continue;
          if (notfirst++) cout << " + ";
          cout << w << char('a'+i-1);
        }
        cout << " = " << ((-e[0])%3+3)%3 << endl;
      }
      cout << endl;
    };

    todo[0];
    vector<EQ> path;
    while (todo.size() > 1) {
      //Print();
      int u = next(todo.begin())->first;
      int j = *todo[u].begin();
      todo[u].erase(j);

      assert(u == Sz(j));
      
      path.push_back(eq[j]);
      auto cp = node[eq[j].rbegin()->first];
      for (int k : cp) {
        int SZ = Sz(k);
        auto&todo_ = todo[SZ];
        if (todo_.count(k)) {
          todo_.erase(k);
          for (auto [i,w] : eq[k]) if (i) node[i].erase(k);
          eq[k] = Insert(eq[j], eq[k]);
          todo[Sz(k)].insert(k);
          for (auto [i,w] : eq[k]) if (i) node[i].insert(k);
        }
        if (todo[SZ].empty()) todo.erase(SZ);
      }
    }

    int ok = 1;
    for (int j : todo[0]) {
      if (eq[j][0]) ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }


    fill(ans.begin()+1, ans.end(), 0);
    /*for (int j : todo[3]) {
      for (auto [i,w] : eq[j]) ans[i] = 0;
    }*/

    while (path.size()) {
      EQ e = path.back();
      path.pop_back();
      int b = e.rbegin()->first;
      //assert(ans[b] == -1);
      int sum = 0;
      for (auto [i,w] : e) {
        if (i != b) {
          assert(ans[i] != -1);
          sum += ans[i]*w;
        }
      }
      ans[b] = ((-sum * e[b])%3+3)%3;
    }
    /*cout << "Ans: ";
    for (int v : ans) cout << v << ' ';
    cout << endl;*/

    ok = 1;
    for (auto e : eq) {
      int sum = 0;
      for (auto [i,w] : e) {
        assert(ans[i] != -1);
        sum += ans[i]*w;
      }
      if (sum%3) ok = 0;
    }
    for (int i = 1; i <= m; i++) if (ans[i] == -1) ans[i] = 0;
    for (int i = 1; i <= m; i++) cout << ans[i]+!ans[i]*3 << ' ';
    cout << endl;
    assert(ok);
  }
}