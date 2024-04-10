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
	int n;
	cin >> n;
	vi a(n - 1);
	for(int i = 0; i < n - 1; i++) cin >> a[i];
	int x, y;
	cin >> x >> y;
	--x;
	--y;
	int ans = 0;
	for(int i = x; i <= y - 1; i++) {
		ans += a[i];
	}
	cout << ans;
}