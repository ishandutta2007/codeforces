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
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = 200000;
	for(int i = 0; i < n; i++) {
		mn = min(mn, abs(a[i] - a[(i + 1) % n]));
	}
	for(int i = 0; i < n; i++) {
		if(abs(a[i] - a[(i + 1) % n]) == mn) {
			cout << i + 1 << ' ' << (i + 1) % n + 1;
			return 0;
		}
	}
}