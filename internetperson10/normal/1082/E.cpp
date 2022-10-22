#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct FTree {
	vector<int> nums;
	int size = 1;
	void init(int n) {
		vector<int>().swap(nums);
		while(size < n) size *= 2;
		nums.resize(size+1);
	}
	void add(int i, int k) {
		while(i <= size) {
			nums[i] += k;
			i += (i & (-i));
		}
	}
	int sum(int i) {
		int ans = 0;
		while(i > 0) {
			ans += nums[i];
			i -= (i & (-i));
		}
		return ans;
	}
};

vector<vector<int>> ind;
int pref[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, x;
	cin >> n >> k;
	ind.resize(500001);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		ind[x].push_back(i);
	}
	for(int i : ind[k]) {
		pref[i]++;
	}
	for(int i = 1; i <= 500000; i++) pref[i] += pref[i-1];
	int ans = 0;
	for(int i = 1; i <= 500000; i++) {
		if(i == k) continue;
		int least = 0, curr = 0;
		for(int j : ind[i]) {
			curr -= pref[j];
			least = min(least, curr);
			curr++;
			ans = max(ans, curr - least);
			curr += pref[j];
		}
	}
	cout << ans + ind[k].size() << '\n';
}