#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> node(n);
    vector<int> deg(n), done(n);

    vector<ll> edges;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
      deg[a]++, deg[b]++;
      edges.push_back((ll)a<<30 | b);
      edges.push_back((ll)b<<30 | a);
    }
    sort(edges.begin(), edges.end());

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] < k-1) {
        q.push(i);
        done[i] = 1;
      }
    }
    while (q.size()) {
      int p = q.front();
      q.pop();
      done[p] = 2;
      for (int i : node[p]) {
        if (deg[i]-- == k-1 && !done[i]) {
          done[i] = 1;
          q.push(i);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (deg[i] == k-1) {
        q.push(i);
        done[i] = 1;
      }
    }
    vector<int> clique;
    while (q.size() && clique.empty()) {
      int p = q.front();
      q.pop();

      if (deg[p] == k-1) {
        clique.push_back(p);
        for (int i : node[p])
          if (done[i] != 2)
            clique.push_back(i);
        assert((int)clique.size() == k);
        int ok = 1;
        for (int i = 0; i < k && ok; i++) {
          for (int j = 0; j < i && ok; j++) {
            if (!binary_search(edges.begin(), edges.end(), (ll)clique[i]<<30|clique[j])) ok = 0;
          }
        }
        if (!ok) clique.clear();
      }
      done[p] = 2;

      for (int i : node[p]) {
        if (--deg[i] < k && !done[i]) {
          done[i] = 1;
          q.push(i);
        }
      }
    }

    vector<int> subset;
    for (int i = 0; i < n; i++) {
      if (!done[i]) subset.push_back(i);
    }
    if (clique.size()) {
      cout << 2 << endl;
      for (int i : clique) cout << i+1 << ' ';
      cout << endl;
    } else if (subset.size()) {
      cout << 1 << ' ' << subset.size() << endl;
      for (int i : subset) cout << i+1 << ' ';
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}