#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 602, mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n;
		deque<int> f;
		while(n--) cin >> x, f.push_back(x);
		vector<int> ans;
		int t = 0;
		while(!f.empty()) {
			ans.push_back(t ? f.back() : f.front());
			t ? f.pop_back() : f.pop_front();
			t ^= 1;
		}
		for(auto i : ans) cout << i << " "; cout << '\n';
	}
}