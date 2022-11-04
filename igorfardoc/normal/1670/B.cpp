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
		int m;
		cin >> m;
		set<char> s1;
		for(int i = 0; i < m; i++) {
			char c1;
			cin >> c1;
			s1.insert(c1);
		}
		int ans = 0;
		int p = -1;
		for(int i = n - 1; i >= 0; i--) {
			if(p != -1) {
				ans = max(ans, p - i);
			}
			if(s1.find(s[i]) != s1.end()) {
				p = i;
			}
		}
		cout << ans << '\n';
	}
}