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
		string s;
		cin >> s;
		if(s[0] != '9') {
			for(int i = 0; i < n; i++) {
				cout << '9' - s[i];
			}
			cout << '\n';
			continue;
		}
		string ans = "";
		bool zam = false;
		for(int i = n - 1; i >= 0; i--) {
			int up = 1;
			int down = s[i] - '0';
			if(zam) --up;
			zam = false;
			if(up < down) {
				up += 10;
				zam = true;
			}
			ans += (char)('0' + (up - down));
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}