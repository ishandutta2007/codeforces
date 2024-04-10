#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> p(n*2, vector<int>(n));
    vector<set<int>> s(n*n);
    for (int i = 0; i < n*2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> p[i][j];
        p[i][j]--;
        s[p[i][j]*n+j].insert(i);
      }
    }
    const ll mod = 998244353;
    vector<int> ans;
    ll count = 1;

    vector<int> done(n*2);

    int lefts = n*n*2;

    function<void(int,int)> del = [&](int pi, int rec) {
      done[pi] = 1;
      vector<int> todel;
      for (int j = 0; j < n; j++) {
        int si = p[pi][j]*n+j;
        s[si].erase(pi);
        lefts--;
        if (rec)
          for (int i : s[si]) {
            todel.push_back(i);
          }
      }
      for (int i : todel) {
        if (!done[i]) del(i,0);
      }
    };

    while ((int)ans.size() < n) {
      assert(lefts);
      int found = 0;
      for (int i = 0; i < n*n; i++) {
        if (s[i].size() == 1) {
          int pi = *s[i].begin();
          ans.push_back(pi);
          del(pi,1);
          assert(lefts <= n*(n-(int)ans.size())*2);
          found = 1;
          break;
        }
      }
      if (found) continue;
      //All 2s
      for (int i = 0; i < n*n; i++) {
        assert(s[i].size() == 2 || s[i].size() == 0);
      }
      count = count*2%mod;
      for (int i = 0; i < n*n; i++) {
        if (s[i].size() == 2) {
          int pi = *s[i].begin();
          ans.push_back(pi);
          del(pi,1);
          assert(lefts <= n*(n-(int)ans.size())*2);
          break;
        }
      }
    }

    cout << count << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}