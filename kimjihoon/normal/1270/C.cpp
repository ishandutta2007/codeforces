#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long s = 0, xs = 0;
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			s += a; xs = (xs ^ a);
		}
		cout << 2 << '\n';
		cout << s + xs << " " << xs << '\n';
	}
	return 0;
}