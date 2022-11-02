#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long k, x; cin >> k >> x;
		cout << (k - 1) * 9LL + x << '\n';
	}
	return 0;
}