#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000], inv[100001];
int par[100001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      inv[a[i]] = i;
    }
    vector<vector<int>> ans;
    int left = n;
    while (left) {
      vector<int> lis;
      for (int i = 0; i < n; i++) {
	if (a[i] == -1) continue;
	int j = upper_bound(lis.begin(), lis.end(), a[i])-lis.begin();
	if (j == lis.size()) lis.push_back(a[i]);
	lis[j] = a[i];
	par[a[i]] = j ? lis[j-1] : -1;
      }
      ll k = lis.size();
      if (k*(k+1)/2 >= left) {
	vector<int> v;
	for (int p = lis[lis.size()-1]; p != -1; p = par[p])
	  v.push_back(p),a[inv[p]] = -1;
	reverse(v.begin(), v.end());
	ans.push_back(v);
	left -= lis.size();
      } else {
	vector<int> v;
	vector<vector<int>> dec;
	for (int i = 0; i < n; i++) {
	  if (a[i] == -1) continue;
	  int j = upper_bound(v.begin(), v.end(), a[i])-v.begin();
	  if (j == v.size()) v.push_back(0), dec.push_back(vector<int>());
	  v[j] = a[i];
	  dec[j].push_back(a[i]);
	}
	for (auto v : dec) ans.push_back(v);
	break;
      }
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
      cout << v.size();
      for (int i : v)
	cout << ' '  << i;
      cout << '\n';
    }
  }
}