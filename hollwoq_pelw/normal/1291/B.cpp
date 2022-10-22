#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	int w[n+1];
	int Mn = 1e9, Mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		if (w[i] < i-1)Mn = min(Mn, i);
		if (w[i] < n-i)Mx = max(Mx, i);
	}
	if (Mx + 1 <= Mn - 1) {
		cout << "Yes" << endl; return;
	}
	cout << "No" << endl;
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}