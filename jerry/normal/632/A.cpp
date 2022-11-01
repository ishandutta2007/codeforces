#include <bits/stdc++.h>
using namespace std;

long long ap, pr;

char buf[64][16];
int n, p;

int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 0;i < n;i++) scanf("%s", buf[i]);
	for (int i = n-1;i >= 0;i--)
		ap = ap*2 + (strlen(buf[i])-4)/4;
	for (int i = 0;i < n;i++)
	{
		pr += (ap*p/2);
		ap >>= 1;
	}
	cout << pr << endl;
	return 0;
}