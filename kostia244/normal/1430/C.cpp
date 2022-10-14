#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, cur = 0;
		cin >> n;
		set<int, greater<>> nums;
		for(int i = 1; i < n; i++) nums.insert(i);
		cur = n;
		vector<array<int, 2>> ops;
		while(nums.size()) {
			if(nums.size() == 1 || (*nums.begin()+cur+1)%2) {
				ops.push_back({cur, *nums.begin()});
				cur = (cur + *nums.begin() + 1)/2;
				nums.erase(nums.begin());
			} else {
				auto it = nums.begin(); it++;
				ops.push_back({cur, *it});
				cur = (cur + *it + 1)/2;
				nums.erase(it);
			}
		}
			cout << cur << '\n';
			for(auto &i : ops) cout << i[0] << " " << i[1] << endl;
	}
}