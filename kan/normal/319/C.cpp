#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

struct tline
{
	int begin;
	ll a, b;
	
	tline(){}
	tline(int begin, ll a, ll b): begin(begin), a(a), b(b) {}
};

const int maxn = 100005;

const ll inf = 2e9;

tline q[maxn];
int a[maxn], b[maxn];
ll ans[maxn];
int n;
int bo, eo;

void add(ll a, ll b)
{
	while (eo - bo > 0)
	{
		ll l = 0;
		ll r = inf;
		while (r - l > 1)
		{
			ll m = (l + r) / 2;
			ll clast = m * q[eo - 1].a + q[eo - 1].b;
			ll cur = m * a + b;
			if (cur <= clast) r = m;
			else l = m;
		}
		if (r <= q[eo - 1].begin) eo--;
		else
		{
// 			cout << "added " << r << ' ' << a << ' ' << b << endl;
			q[eo] = tline(r, a, b);
			eo++;
			return;
		}
	}
// 	cout << "added " << 0 << ' ' << a << ' ' << b << endl;
	q[eo] = tline(0, a, b);
	eo++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	q[0] = tline(0, b[0], 0);
	bo = 0;
	eo = 1;
	ans[0] = 0;
	for (int i = 1; i < n; i++)
	{
		while (eo - bo > 1 && q[bo + 1].begin <= a[i]) bo++;
// 		cout << i << ' ' << q[bo].a << endl;
		ans[i] = q[bo].a * a[i] + q[bo].b;
		add(b[i], ans[i]);
	}
	cout << ans[n - 1] << endl;
	return 0;
}