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
		int n, c;
		cin >> n >> c;
		vi am(c + 1);
		vi pref(c + 2);
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			++am[a];
		}
		for(int i = 1; i <= c + 1; i++) {
			pref[i] = pref[i - 1] + am[i - 1];
		}
		bool ok = true;
		for(int i = 1; i <= c; i++) {
			if(am[i] == 0) continue;
			for(int j = 1; j * i <= c; j++) {
				if(am[j] > 0) continue;
				int l = i * j;
				int r = min(c, i * (j + 1) - 1);
				if(pref[r + 1] - pref[l] > 0) ok = false;
			}
		}
		if(ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}