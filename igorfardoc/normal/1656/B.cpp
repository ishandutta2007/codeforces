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
		vi a(n);
		map<int, int> am;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			++am[a[i]];
		}
		bool ok = false;
		for(int i = 0; i < n; i++) {
			--am[a[i]];
			int need = a[i] - k;
			if(am[need] > 0) {
				ok = true;
				break;
			}
			++am[a[i]];
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}