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
		int x, y;
		cin >> x >> y;
		if(x == 0 && y == 0) {
			cout << 0 << '\n';
			continue;
		}
		int here = sqrt(x * x + y * y);
		if(here * here == x * x + y * y) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}