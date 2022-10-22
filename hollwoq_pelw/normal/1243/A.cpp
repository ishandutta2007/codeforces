#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	sort(a,a+n);
	int res = n;
	while(a[n-res] < res) res --;
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)solve();
}