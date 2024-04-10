#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;

using namespace std;

vector<pair<ll, int>> ns;
vector<pair<int, ll>> ps;
vector<pair<ll, ll>> qs;

struct FTree {
	int size = 1;
	vector<int> nums;
	void init(int n) {
		while(size < n) size *= 2;
		nums.resize(size+1);
	}
	void set(int n) {
		n++;
		while(n <= size) {
			nums[n]++;
			n += (n & (-n));
		}
	}
	int find(int x) {
		int k = size/4;
		int curr = size/2;
		int g;
		int ans;
		g = nums[curr];
		ans = size;
		if(g == x) ans = min(ans, curr);
		while(k > 0) {
			// cout << g << ' ' << curr << ' ' << k << '\n';
			if(g >= x) {
				g -= nums[curr];
				curr -= k;
				g += nums[curr];
			}
			else {
				curr += k;
				g += nums[curr];
			}
			if(g == x) ans = min(ans, curr);
			k /= 2;
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n, q;
	cin >> m >> n >> q;
	ns.resize(n);
	qs.resize(q);
	ps.resize(n+1);
	FTree ft;
	ft.init(n+1);
	for(int i = 0; i < n; i++) {
		ns[i] = {0, i};
	}
	for(int i = 0; i < q; i++) qs[i] = {0, i};
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		ns[x].first++;
	}
	for(int i = 0; i < q; i++) {
		ll x;
		cin >> x;
		qs[i].first = x;
	}
	sort(ns.begin(), ns.end());
	int x = 0;
	ns.push_back({(ll)1000000000000500001, 1});
	ll k = -1;
	int g = 0;
	for(int i = 0; i < n; i++) {
		if(k == -1) {
			ft.set(ns[i].second);
		}
		if(ns[i].first != ns[i+1].first) {
			if(g > 0) ps[g - 1].first = i+1;
			else k = i+1;
			ps[g] = {-1, ns[i+1].first - ns[i].first};
			// cout << i+1 << ' ' << ns[i+1].first - ns[i].first << '\n';
			g++;
		}
	}
	// for(int i = 0; i < ps.size(); i++) {
	// 	cout << ps[i].first << ' ' << ps[i].second << '\n';
	// }
	sort(qs.begin(), qs.end());
	int j = 0;
	ll ol = m;
	bool sad = false;
	for(int i = 0; i < qs.size(); i++) {
		sad = false;
		// cout << qs[i].first << ' ' << qs[i].second << '\n';
		while(j != g - 1) {
			if(ol + k*ps[j].second >= qs[i].first) break;
			// cout << "Did it\n";
			sad = true;
			ol += k * ps[j].second;
			for(int l = k; l < ps[j].first; l++) {
				// vv.push_back(ns[l].second);
				ft.set(ns[l].second);
			}
			k = ps[j].first;
			j++;
		}
		// cout << ol << '\n';
		// if(sad) sort(vv.begin(), vv.end());
		// for(int j = 0; j < vv.size(); j++) cout << vv[j] << ' ';
		// cout << '\n';
		swap(qs[i].first, qs[i].second);
		qs[i].second = ft.find(((qs[i].second - ol - 1)%k) + 1);
	}
	sort(qs.begin(), qs.end());
	for(int i = 0; i < q; i++) {
		cout << qs[i].second << '\n';
	}
}