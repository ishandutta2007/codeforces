#include <iostream>
#define int long long
using namespace std;
int N, T, a, b, c, d;
int suc[400];
char st[10] = "abacaba";
char st2[10] = "abac";
char st3[10] = "abacab";
char arr[100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		int i;
		for (i = a; i <= b; i++)
		{
			int x = c / i * i;
			if (x > 0 && c - x <= b - a)
			{
				cout << i << ' ' << b <<' '<< b - c + x << '\n';
				break;
			}
			x += i;
			if (x > 0 && x-c <= b - a)
			{
				cout << i << ' ' << b-x+c << ' ' << b << '\n';
				break;
			}
		}
	}
}