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
		int n;
		cin >> n;
		int m;
		string s;
		cin >> s;
		m = s.size();
		bool eq = true;
		for(int i = 0; i < m - 1; i++) {
			if(s[i] != s[i + 1]) eq = false;
		}
		if(eq) {
			cout << n << '\n';
			continue;
		}
		int amd = 0;
		int amr = 0;
		for(int i = 0; i < m; i++) {
			if(s[i] == 'R') {
				++amr;
			} else {
				++amd;
			}
		}
		ll ans = 0;
		int now = n - 1;
		for(int i = 0; i < m; i++) {
			if(s[i] == 'D') {
				now = min(now - 1, amd - 1);
				continue;
			}
			ans += now;
		}
		ans += now;
		now = n - 1;
		for(int i = 0; i < m; i++) {
			if(s[i] == 'R') {
				now = min(now - 1, amr - 1);
				continue;
			}
			ans += now;
		}
		ans += now;
		cout << (ll)n * n - ans << '\n';
	}

}