#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, e[101], mn = 1000000000;
	memset(e, 0, sizeof e);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> e[i];
	for(int x = 1; x <= n; x++) {
		int total = 0;
		for(int i = 1; i <= n; i++) {
			total += e[i] * 2 * (abs(x - i) + (i - 1) + (x - 1));
		}
		mn = min(mn, total);
	}
	cout << mn;
}