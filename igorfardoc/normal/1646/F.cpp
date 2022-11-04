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
	int n;
	cin >> n;
	vvi am(n, vi(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int a;
			cin >> a;
			--a;
			++am[i][a];
		}
	}
	vvi ans;
	while(true) {
		bool ok = true;
		int id = -1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(am[i][j] == 0) {
					id = i;
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) break;
		vi anshere(n);
		for(int i = id; ; i = (i + 1) % n) {
			int id1;
			for(int j = 0; j < n; j++) {
				if(am[i][j] > 1) {
					id1 = j;
					break;
				}
			}
			anshere[i] = id1;
			--am[i][id1];
			++am[(i + 1) % n][id1];
			if(i == (id - 1 + n) % n) break;
		}
		ans.push_back(anshere);
	}
	for(int i = 1; i <= n - 1; i++) {
		for(int j = 0; j < i; j++) {
			vi anshere(n);
			for(int k = 0; k < n; k++) {
				anshere[k] = (k + i - j) % n;
			}
			ans.push_back(anshere);
		}
	}
	cout << ans.size() << '\n';
	for(const auto& el : ans) {
		for(const auto& el1 : el) {
			cout << el1 + 1 << ' ';
		}
		cout << '\n';
	}

}