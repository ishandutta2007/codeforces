#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
vector<int>x,y,n;
int gcd(int a, int b, int x)
{
	
	if (b == 0)
		return 0;
	if (a % b == x % b && a >= x)
		return x;
	return gcd(b, a % b, x);
}
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << (gcd(a, b, c)||a==c||b==c? "YES" : "NO") << '\n';
	}
}