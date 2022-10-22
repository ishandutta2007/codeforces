#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
set<pii> v;
int main()
{
	int xa, ya, xb, yb, xc, yc,i;
	scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
	int mid = 0;
	int miny = min(ya, min(yb, yc));
	int maxy = max(ya, max(yb, yc));
	if (xa <= xb && xb <= xc)mid = xb;
	if (xc <= xb && xb <= xa)mid = xb;
	if (xb <= xa && xa <= xc)mid = xa;
	if (xc <= xa && xa <= xb)mid = xa;
	if (xa <= xc && xc <= xb)mid = xc;
	if (xb <= xc && xc <= xa)mid = xc;
	for (i = miny; i <= maxy; i++)v.insert({ mid,i });
	for (i = min(xa, mid); i <= max(xa, mid); i++)v.insert({ i,ya });
	for (i = min(xb, mid); i <= max(xb, mid); i++)v.insert({ i,yb });
	for (i = min(xc, mid); i <= max(xc, mid); i++)v.insert({ i,yc });
	printf("%d\n", v.size());
	for (pii th : v)printf("%d %d\n", th.first, th.second);
	getchar(); getchar();
}