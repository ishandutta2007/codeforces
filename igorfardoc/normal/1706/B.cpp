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
		vi dp1(n, 0), dp2(n, 0);
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			--a;
			if(i % 2 == 0) {
				dp1[a] = max(dp1[a], dp2[a] + 1);
			} else {
				dp2[a] = max(dp2[a], dp1[a] + 1);
			}
		}
		for(int i = 0; i < n; i++) {
			cout << max(dp1[i], dp2[i]) << ' ';
		}
		cout << '\n';
	}
}