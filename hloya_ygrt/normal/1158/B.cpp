#include <iostream>
#include <bits/stdc++.h>
// #include <vector>
// #include <map>
// #include <set>

#define pb push_back
using namespace std;

const int maxn = 5e5 + 100;


set<vector<int> > solve(int n, int k) {
	set<vector<int> > ans;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> a(n);
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				a[j] = 1;
			else
				a[j] = 0;
		}

		for (int len = 1; len <= k; len++) {
			map<vector<int>, int> e;
			bool ok = 1;
			for (int p = 0; p + len <= n && ok; p++) {
				vector<int> st;
				for (int i = p; i < p + len; i++)
					st.push_back(a[i]);
				e[st]++;
			}
			for (auto i : e)
				if (i.second == 1)
					ok = 0;
			if (!ok) {
				if (len == k) {
					ans.insert(a);
					// for (int i = 0; i < n; i++)
					// 	cout << a[i] << ' ';
					// cout << "\n";
				} else break;
			}
		}
	}
	return ans;
}

vector<int> brute(int n, int k) {
	vector<int>  ans;
	if (k == 1) {
		ans.pb(0);
		for (int i = 0; i < n - 1; i++)
			ans.pb(1);
		return ans;
	} 

	if (n == k) {
		for (int i = 0; i < n; i++)
			ans.pb(1);
		return ans;
	}
	int de = n - k;
	if (k % 2 == 1) {
		int mda = de / 2 + 1;

		for (int i = 0; i < n; i++)
			if ((i) % mda == 0)
				ans.pb(0);
			else
				ans.pb(1);
	} else {
		int mda = de / 2 + 1;
		for (int i = 0; i < n; i++)
			if ((i + 1) % mda == 0)
				ans.pb(1);
			else
				ans.pb(0);
	}
	return ans;
}	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);

	// for (int k = 1; k <= 16; k++) {
	// 	for (int n = k; n <= 16; n += 2) {
	// 		vector<int> res = brute(n, k);
	// 		set<vector<int> >  mda = solve(n, k);
	// 		if (!mda.count(res)) {
	// 			cout << n << ' ' << k << endl;
	// 			// exit(0);
	// 		}
	// 	}
	// }


	int n, k;
	cin >> n >> k;
	// brute(n,  k);
	// solve(3, 1);
	// cout << endl;
	vector<int> ans = brute(n, k);
	for (auto e : ans) {
		cout << e;
	}
	return 0;
}