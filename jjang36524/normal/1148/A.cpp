#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(2 * c + min(a, b) * 2 + (a != b), min(a, b) * 2 + (a != b));
}