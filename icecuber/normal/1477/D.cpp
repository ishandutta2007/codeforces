#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> node(n);
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      node[l].insert(r);
      node[r].insert(l);
    }

    set<int> left;
    for (int i = 0; i < n; i++)
      left.insert(i);


    vector<set<int>> inv(n);

    vector<int> done(n);
    vector<int> vlist;
    function<void(int,int)> dfs = [&](int p, int par = -1) {
                 if (done[p]++) return;
                 vlist.push_back(p);
                 for (int i : inv[p])
                   if (i != par) dfs(i,p);
               };

    queue<int> q;
    vector<vector<int>> tree = {};
    while (left.size()) {
      if (q.empty()) {
        int p = *left.begin();
        tree.push_back({p});
        q.push(p);
        left.erase(left.begin());
      }
      int p = q.front();
      q.pop();
      vector<int> toerase;
      for (int i : left) {
        if (!node[p].count(i)) {
          inv[p].insert(i);
          inv[i].insert(p);
          tree.back().push_back(i);
          q.push(i);
          toerase.push_back(i);
        }
      }
      for (int i : toerase)
        left.erase(i);
    }

    vector<vector<int>> ans(2, vector<int>(n,-1));
    int cur = 1;

    for (vector<int> t : tree) {
      for (int p : t) {
        set<int> cp = inv[p];
        for (int i : cp) {
          if ((int)inv[p].size() > 1 &&
              (int)inv[i].size() > 1) {
            inv[p].erase(i);
            inv[i].erase(p);
          }
        }
      }

      for (int p : t) {
        if (!done[p]) {
          vlist.clear();
          dfs(p, -1);
          int root = -1;
          for (int i : vlist) {
            int ok = 1;
            for (int j : inv[i])
              if ((int)inv[j].size() > 1) ok = 0;
            if (ok) {
              root = i;
              break;
            }
          }
          /*cout << "VLIST: ";
          for (int i : vlist)
            cout << i << ' ';
            cout << endl;*/
          assert(root != -1);

          int A = cur;
          int B = cur+vlist.size()-1;
          for (int i : vlist) {
            if (i == root) {
              ans[0][i] = B;
              ans[1][i] = A;
            } else {
              ans[0][i] = cur++;
              ans[1][i] = cur;
            }
          }
          cur++;
        }
      }
    }
    for (vector<int> a : ans) {
      for (int i : a) cout << i << ' ';
      cout << endl;
    }
  }
}