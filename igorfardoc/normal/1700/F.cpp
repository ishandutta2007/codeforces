#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

void go(int& start, vi& mass) {
	while(start < mass.size() && mass[start] == 0) ++start;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vi a(n), b(n), c(n), d(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
	for(int i = 0; i < n; i++) {cin >> b[i]; sum += b[i];}
	for(int i = 0; i < n; i++) {cin >> c[i]; sum -= c[i];}
	for(int i = 0; i < n; i++) {cin >> d[i]; sum -= d[i];}
	if(sum != 0) {
		cout << -1;
		return 0;
	}
	int am1 = 0;
	int am2 = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		am1 += a[i] - c[i];
		am2 += b[i] - d[i];
		while((am1 < 0 && am2 > 0) || (am2 < 0 && am1 > 0)) {
			if(am1 < 0 && am2 > 0) {
				++am1;
				--am2;
				++ans;
			} else {
				++am2;
				--am1;
				++ans;
			}
		}
		ans += abs(am1) + abs(am2);
	}
	cout << ans;


}