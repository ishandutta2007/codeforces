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
		bool there1 = false;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 1) there1 = true;
		}
		if(!there1) {
			cout << "YES\n";
			continue;
		}
		sort(a.begin(), a.end());
		bool ok = true;
		for(int i = 0; i < n - 1; i++) {
			if(a[i + 1] - a[i] == 1) {
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