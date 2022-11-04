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
		string s;
		cin >> s;
		int ans = -1;
		if(s.size() == 2) {
			ans = s[1] - '0';
		} else {
			ans = 11;
			for(int i = 0; i < s.size(); i++) {
				ans = min(ans, s[i] - '0');
			}
		}
		cout << ans << '\n';
	}
}