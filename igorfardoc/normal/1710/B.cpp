#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<array<int, 3>> a(n);
		set<int> all;
		for(int i = 0; i < n; i++) {
			cin >> a[i][0] >> a[i][1];
			all.insert(a[i][0]);
			a[i][2] = i;
		}
		sort(a.begin(), a.end());
		vl b(all.size());
		vi num;
		map<int, int> where;
		for(const auto& el : all) {
			num.push_back(el);
			where[el] = num.size() - 1;
		}
		ll f = 0;
		ll g = 0;
		int pt = 0;
		vector<vector<int>> dl(all.size());
		for(int i = 0; i < all.size(); i++) {
			for(const auto& el : dl[i]) {
				g -= el;
				++f;
			}
			b[i] += g + f * num[i];
			while(pt < n && a[pt][0] == num[i]) {
				b[i] += a[pt][1];
				g += a[pt][1] + a[pt][0];
				--f;
				int id = upper_bound(num.begin(), num.end(), a[pt][0] + a[pt][1]) - num.begin();
				if(id < all.size()) {
					dl[id].push_back(a[pt][1] + a[pt][0]);
				}
				++pt;
			}
		}
		//////
		f = 0;
		g = 0;
		pt = n - 1;
		dl.assign(all.size(), {});
		for(int i = (int)all.size() - 1; i >= 0; i--) {
			for(const auto& el : dl[i]) {
				g -= el;
				--f;
			}
			b[i] += g + f * num[i];
			while(pt >= 0 && a[pt][0] == num[i]) {
				g += a[pt][1] - a[pt][0];
				++f;
				int id = upper_bound(num.begin(), num.end(), a[pt][0] - a[pt][1]) - num.begin() - 1;
				if(id >= 0) {
					dl[id].push_back(a[pt][1] - a[pt][0]);
				}
				--pt;
			}
		}
		vl mass1(all.size());
		vl mass2(all.size());
		for(int i = 0; i < all.size(); i++) {
			mass1[i] = max(0ll, b[i] - m);
			if(i > 0 && mass1[i - 1] > 0) {
				mass1[i] = max(mass1[i], mass1[i - 1] + num[i] - num[i - 1]);
			}
		}
		for(int i = (int)all.size() - 1; i >= 0; i--) {
			mass2[i] = max(0ll, b[i] - m);
			if(i < (int)all.size() - 1 && mass2[i + 1] > 0) {
				mass2[i] = max(mass2[i], mass2[i + 1] + num[i + 1] - num[i]);
			}
		}
		/*for(const auto& el : b) {
			cout << el << ' ';
		}
		cout << endl;*/
		vi ans(n, 0);
		for(int i = 0; i < n; i++) {
			int id = where[a[i][0]];
			if(max(mass1[id], mass2[id]) <= a[i][1]) {
				ans[a[i][2]] = 1;
			}
		}
		for(const auto& el : ans) {
			cout << el;
		}
		cout << '\n';

	}

}