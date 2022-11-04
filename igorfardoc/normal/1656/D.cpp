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
		ll n;
		cin >> n;
		ll now = 2;
		while(n % now == 0) now *= 2;
		ll other = n / (now / 2);
		if(min(other, now) == 1) {
			cout << -1 << '\n';
			continue;
		}
		cout << min(other, now) << '\n';
	}
}