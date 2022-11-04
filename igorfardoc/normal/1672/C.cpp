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
		for(int i = 0; i < n; i++) cin >> a[i];
		int fir = -1;
		int last = -1;
		for(int i = 0; i < n - 1; i++) {
			if(a[i] == a[i + 1]) {
				last = i;
				if(fir == -1) fir = i;
			}
		}
		if(last == fir) {
			cout << 0 << '\n';
			continue;
		}
		if(last == fir + 1) {
			cout << 1 << '\n';
			continue;
		}
		cout << last - fir - 1 << '\n';
	}

}