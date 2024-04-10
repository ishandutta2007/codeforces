#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long s = 0;
		bool f = true, tf = false;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a != 0 && tf) f = false;
			s += a;
			if (s < 0) f = false;
			else if (s == 0) tf = true;
		}
		if (s != 0) f = false;
		if (f) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}