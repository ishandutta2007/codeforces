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
    vector<int> cnt(n);
    vector<vector<int>> a(n, vector<int>(2));
    for (int k : {0,1})
      for (int i = 0; i < n; i++) {
	cin >> a[i][k];
	a[i][k]--;
	cnt[a[i][k]]++;
      }
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (cnt[i] != 2) ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    vector<vector<pair<int,int>>> node(n);
    for (int i = 0; i < n; i++) {
      node[a[i][0]].emplace_back(a[i][1], i);
      node[a[i][1]].emplace_back(a[i][0], i);
    }
    vector<int> done(n);
    vector<tuple<int,int,int>> path;
    function<void(int,int,int)> dfs = [&](int p, int par, int ei) {
      if (done[p]++) return;
      path.emplace_back(p, par, ei);
      for (auto [i, ei_] : node[p]) {
	if (ei == ei_) continue;
	dfs(i, p, ei_);
      }
    };
    vector<int> ans;
    int expect = 0;
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      path.clear();
      dfs(node[i][0].first, i, node[i][0].second);
      int score[2] = {};
      for (auto [x,y,ei] : path) {
	//cout << x << ' ' << y << ' ' << ei << endl;
	score[x != a[ei][0]]++;
      }
      expect += min(score[0], score[1]);
      for (auto [x,y,ei] : path) {
	if (score[0] < score[1]) swap(x,y);
	if (x != a[ei][0])
	  ans.push_back(ei);
      }
    }
    assert((int)ans.size() == expect);
    cout << ans.size() << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;

    /*for (int i : ans)
      swap(a[i][0], a[i][1]);
    for (int k : {0,1}) {
      set<int> s;
      for (int i = 0; i < n; i++)
	s.insert(a[i][k]);
      assert((int)s.size() == n);
      }*/
  }
}