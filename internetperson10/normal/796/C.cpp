#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums;
vector<vector<int>> adj;
multiset<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 1999999999;
	cin >> n;
	nums.resize(n);
	adj.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i < n; i++) {
		s.insert(nums[i]+2);
	}
	// for(int a : s) {
	// 	cout << a << '\n';
	// }
	for(int i = 0; i < n; i++) {
		auto it = s.find(nums[i]+2);
		s.erase(it);
		s.insert(nums[i]);
		for(int j : adj[i]) {
			it = s.find(nums[j]+2);
			s.erase(it);
			s.insert(nums[j]+1);
		}
		it = s.end();
		it--;
		ans = min(ans, *it);
		it = s.find(nums[i]);
		s.erase(it);
		s.insert(nums[i]+2);
		for(int j : adj[i]) {
			it = s.find(nums[j]+1);
			s.erase(it);
			s.insert(nums[j]+2);
		}
	}
	cout << ans << '\n';
}