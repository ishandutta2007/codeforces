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
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int mn = 0;
		for(int i = 0; i < n; i++) mn += (a[i] < 0);
		vi b;
		for(int i = 0; i < n; i++) {
			if(i < mn) {
				b.push_back(-abs(a[i]));
			} else {
				b.push_back(abs(a[i]));
			}
		}
		bool ok = true;
		for(int i = 0; i < n - 1; i++) {
			if(b[i] > b[i + 1]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}