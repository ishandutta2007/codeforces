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
		string s = "";
		for(int i = 0; i < m; i++) {
			s += 'B';
		}
		for(int i = 0; i < n; i++) {
			int b;
			cin >> b;
			--b;
			if(b >= m / 2) b = m - 1 - b;
			if(s[b] == 'A') {
				s[m - 1 - b] = 'A';
			} else {
				s[b] = 'A';
			}
		}
		cout << s << '\n';
	}
}