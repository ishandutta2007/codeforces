#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if ((max({ a,b,c })) == (a + b + c - max({ a,b,c }))||(a==b&&c%2==0)|| (a == c && b % 2 == 0)|| (c == b && a % 2 == 0))
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
}