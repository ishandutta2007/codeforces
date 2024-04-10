#include <iostream>
using namespace std;
int a, b, q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> q;
	while (q--)
	{
		cin >> b >> a;
		if (3 * a + 1 < b || 3 * b + 1 < a)
		{
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES"<<'\n';
		int i = 3;
		while (a && b)
		{
			cout << 3 << ' ' << i << '\n';
			cout << 3 << ' ' << i + 1 << '\n';
			a--; b--;
			i += 2;
		}
		if (a + b == 0)
			continue;
		if (a)
		{
			cout << 3 << ' ' << i<<'\n';
			a--;
			int j = 4;
			while (a)
			{
				cout << 2 << ' ' << j << '\n';
				a--; 
				if (!a)
					break;
				cout << 4 << ' ' << j << '\n';
				j += 2;
				a--;
			}
		}
		else
		{
			cout << 3 << ' ' << 2 << '\n';
			b--;
			int j = 3;
			while (b)
			{
				cout << 2 << ' ' << j << '\n';
				b--;
				if (!b)
					break;
				cout << 4 << ' ' << j << '\n';
				j += 2;
				b --;
			}
		}
	}
}