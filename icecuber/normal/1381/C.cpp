#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    set<tuple<int,int,int>> ms;
    map<int,int> cnt;
    vector<pair<int,int>> a(n);
    set<int> left;
    for (int i = 1; i <= n+1; i++)
      left.insert(i);
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      inp[i] = b;
      if (left.count(b)) left.erase(b);
      ms.insert({cnt[b]++, b, i});
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < x; i++) {
      auto it = *ms.rbegin();
      ms.erase(it);
      ans[get<2>(it)] = get<1>(it);
    }
    vector<pair<int,int>> v;
    /*for (int i = 0; i < n-y; i++) {
      auto it = *ms.rbegin();
      ms.erase(it);
      v.emplace_back(get<1>(it), get<2>(it));
      //ans[get<2>(it)] = *left.begin();
      }*/
    for (int i = 0; i < n-x; i++) {
      auto it = *ms.begin();
      ms.erase(it);
      v.emplace_back(get<1>(it), get<2>(it));
    }
    sort(v.begin(), v.end());
    int vl = n-x;
    assert((int)v.size() == vl);
    int fails = 0;
    for (int i = 0; i < vl; i++) {
      if (v[(i+vl/2)%vl].first == v[i].first) {
	ans[v[i].second] = *left.begin();
	fails++;
      } else {
	ans[v[i].second] = v[(i+vl/2)%vl].first;
      }
    }
    if (fails > n-y) cout << "NO" << endl;
    else {
      for (int i = 0; i < n; i++) {
	if (fails < n-y && ans[i] != inp[i] && ans[i] != *left.begin()) {
	  ans[i] = *left.begin();
	  fails++;
	}
      }
      cout << "YES" << endl;
      for (int i : ans) cout << i << ' ';
      cout << endl;
    }
  }
}