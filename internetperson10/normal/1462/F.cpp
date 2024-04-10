#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<pair<int, int>> nums;
bool taken[200001];
map<int, int> m;
set<int> es;

struct FTree {
	vector<int> nums;
	int size;
	void init(int n) {
		vector<int>().swap(nums);
		size = 1;
		while(size < n) size *= 2;
		nums.resize(size+2);
	}
	void add(int n) {
		while(n <= size) {
			nums[n]++;
			n += (n & (-n));
		}
	}
	int sum(int n) {
		if(n == -1) return 0;
		if(n >= size) return sum(size-1);
		int ans = 0;
		while(n > 0) {
			ans += nums[n];
			n -= (n & (-n));
		}
		return ans;
	}
	void print() {
		for(int i = 0; i <= size; i++) {
			cout << nums[i] << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	FTree s, b; // small, big
	while(t--) {
		int n;
		cin >> n;
		int ans = n, best = n;
		nums.resize(n);
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			nums[i] = {x, y};
			es.insert(x);
			es.insert(y);
		}
		int i = 1;
		for(int x : es) {
			m[x] = i++;
		}
		for(int i = 0; i < n; i++) {
			nums[i].first = m[nums[i].first];
			nums[i].second = m[nums[i].second];
		}
		s.init(2*n);
		b.init(2*n);
		for(int i = 0; i < n; i++) {
			s.add(nums[i].first);
			b.add(nums[i].second);
			// s.print(); b.print();
		}
		for(int i = 0; i < n; i++) {
			ans = b.sum(nums[i].first-1) + (n - s.sum(nums[i].second));
			best = min(best, ans);
		}
		cout << best << '\n';
		vector<pair<int, int>>().swap(nums);
		map<int, int>().swap(m);
		set<int>().swap(es);
	}
}