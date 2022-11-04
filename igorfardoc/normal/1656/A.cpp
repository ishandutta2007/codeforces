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
		vi a(n);
		int mn = 1000000001;
		int mx = -1;
		int mnid = -1;
		int mxid = -1;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if(a < mn) {
				mn = a;
				mnid = i;
			}
			if(a > mx) {
				mx = a;
				mxid = i;
			}
		}
		cout << mxid + 1 << ' ' << mnid + 1 << '\n';
	}
}