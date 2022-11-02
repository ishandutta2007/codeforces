#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int pr[2] = { 0, 0 };
		bool f = true;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			int t = (a & 1);
			if (pr[t] > a) 
				f = false;
			pr[t] = a;
		}
		if (f) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}