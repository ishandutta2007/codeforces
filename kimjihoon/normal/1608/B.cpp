#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, a, b; cin >> n >> a >> b;
		if (a + b > n - 2 || abs(a - b) > 1) {
			cout << -1 << '\n';
			continue;
		}
		int t = 1, rt = n;
		if (a < b) swap(t, rt);
		for (int i = 1; i <= n; i++) {
			if (i <= a + b + 1) {
				cout << t << " ";
				if (t < rt) t++;
				else t--;
				swap(t, rt);
			}
			else {
				cout << rt << " ";
				if (rt < t) rt++;
				else rt--;
			}
		}
		cout << '\n';
	}
	return 0;
}