#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		cin >> a;
		cout << ((a[0] + a[1] + a[2] == a[3] + a[4] + a[5]) ? "YES" : "NO") << '\n';
	}
}