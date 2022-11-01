#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 100500;

int eqx[maxn];
int eqy[maxn];
int sumx[maxn], sumy[maxn];

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
};
int rev (int x)
{
	int y = 0;
	while (x)
	{
		y = y*10 + x%10;
		x /= 10;
	}
	return y;
};
pii geteq (int x)
{
	int y = rev(x);
	int g = gcd(x, y);
	return make_pair(x/g, y/g);
}
void init();
void solve();

int maxx, maxy, w;
long long X = 10000000, Y = 100000000;
void relax (long long x, long long y)
{
	if (x*y < X*Y)
		X=x, Y=y;
};
int main()
{
	cin >> maxx >> maxy >> w;
	init();
	solve();
	if (X == 10000000)
		cout << -1;
	else
		cout << X << " " << Y;	
};
void init()
{
	map<pii, int> t;
    pii k;
	forn(i, 100000)
    {
        k = geteq(i+1);
		t[k] = 0;
        t[mp(k.second, k.first)] = 0;
    }
	int cnt = 0;
	for (map<pii, int> :: iterator it = t.begin(); it != t.end(); it++)
		it->se = cnt++;
	for (int i = 1; i <= 100000; i++)
	{
		pii k = geteq(i);
		eqx[i] = t[k];
		eqy[i] = t[mp(k.se, k.fi)];
	}	                           
};
void solve()
{	
	int y = 1;
	sumy[eqy[1]] = 1;

	int x;

	for (x = 1; x <= maxx; x++)
		sumx[eqx[x]]++;
    x--;

 	long long total = sumx[eqx[1]];

 	if (total >= w)
 		relax(x, y);

 	bool upd = 1;	
	while (upd)
	{
		upd = 0;
		while (total >= w && x > 1)
		{
			upd = 1;
			relax(x, y);
			total -= sumy[eqx[x]];
			sumx[eqx[x]]--;

			x--;
		}
		if (total >= w)
			relax(x, y);
		while (total < w && y < maxy)
		{
			upd = 1;
			y++;
			total += sumx[eqy[y]];
			sumy[eqy[y]]++;
		}
		if (total >= w)
			relax(x, y);
	}
};