#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main()
{
	cin >> a >> b;
	while (a > 0 && b > 0)
	{
		if (a < b) swap(a, b);
		a -= 2; b++;
		if (a < 0) break;
		c++;
	}
	cout << c << endl;
	return 0;
}