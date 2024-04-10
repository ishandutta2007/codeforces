#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c = 0;
	for (cin >> a >> b;a <= b;a++) for (int i = a;i;i /= 10) switch (i%10)
	{
	case 8:
		c++;
	case 0:
	case 6:
	case 9:
		c++;
	case 2:
	case 3:
	case 5:
		c++;
	case 4:
		c++;
	case 7:
		c++;
	case 1:
		c += 2;
	}
	cout << c << endl;
	return 0;
}