#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;

int sgn(ll x)
{
	if (x<0)
		return -1;
	else
		return 1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ll a, b, x1, x2, y1, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	a *= 2, b *= 2;
	ll xp1 = x1+y1, yp1 = x1-y1, xp2 = x2+y2, yp2 = x2-y2;
	ll d=0;
	if (xp1<xp2)
		swap(xp1, xp2);
	if ((xp1 > 0) == (xp2 > 0))
		d = max(d, xp1/a-xp2/a);
	else
		d = max(d, xp1/a + abs(xp2)/a + 1);
		
	if (yp1<yp2)
		swap(yp1, yp2);
	if ((yp1 > 0) == (yp2 > 0))
		d = max(d, yp1/b-yp2/b);
	else
		d = max(d, yp1/b + abs(yp2)/b + 1);
	
	cout << d;
	
	return 0;
}