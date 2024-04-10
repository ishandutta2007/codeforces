#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		ll u, v;
		cin >> u >> v;
		cout << u * u << " " << -v * v << endl;
	}
	return 0;
}