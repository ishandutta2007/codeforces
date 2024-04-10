#include <cstdio>
#include <iostream>

using namespace std;

long long n[3];
long long a, b, c;
long long d, e, f;
long long h;
long long ans;
char x;

int main()
{
	while (x != '\n')
	{
		scanf("%c", &x);
		if (x == 'B')
			n[0]++;
		else if (x == 'S')
			n[1]++;
		else if (x == 'C')
			n[2]++;
	}
	cin >> a >> b >> c >> d >> e >> f >> h;
	long long can = 2147483647;
	if (n[0])
		can = min(can, a/n[0]);
	else	a = 0;
	if (n[1])
		can = min(can, b/n[1]);
	else	b = 0;
	if (n[2])
		can = min(can, c/n[2]);
	else	c = 0;
	ans += can;
	a -= n[0]*can; b -= n[1]*can; c -= n[2]*can;
	while (a > 0 || b > 0 || c > 0)
	{
		if (a < n[0])
		{
			h -= d*(n[0]-a);
			a = n[0];
		}
		if (b < n[1])
		{
			h -= e*(n[1]-b);
			b = n[1];
		}
		if (c < n[2])
		{
			h -= f*(n[2]-c);
			c = n[2];
		}
		if (h < 0)
		{
			cout << ans << "\n";
			return 0;
		}
		ans++;
		a -= n[0]; b -= n[1]; c -= n[2];
	}

	can = h / (n[0]*d+n[1]*e+n[2]*f);
	ans += can;

	cout << ans << "\n";
	return 0;
}