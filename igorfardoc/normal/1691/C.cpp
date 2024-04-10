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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		for(int i = n - 1; i >= 0; i--) {
			if(s[i] == '1' && k >= n - i - 1) {
				k -= n - i - 1;
				for(int j = i; j < n - 1; j++) {
					swap(s[j], s[j + 1]);
				}
				break;
			}
		}
		for(int i = 0; i < n - 1; i++) {
			if(s[i] == '1' && k >= i) {
				k -= i;
				for(int j = i; j > 0; j--) {
					swap(s[j], s[j - 1]);
				}
				break;
			}
		}
		int ans = 0;
		ans += 10 * (s[0] - '0');
		ans += s[n - 1] - '0';
		for(int i = 1; i < n - 1; i++) {
			ans += 11 * (s[i] - '0');
		}
		cout << ans << '\n';
	}
}