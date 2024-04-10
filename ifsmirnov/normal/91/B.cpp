#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100500;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int a[maxn];
int mn[maxn];
int res[maxn];

void solve();

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	reverse(a, a+n);
	
	solve();
	
	reverse(res, res+n);
	forn(i, n) printf("%d ", res[i]);
	
	return 0;
};
void solve()
{
	mn[0] = a[0];
	forn(i, n-1)
		mn[i+1] = min(mn[i], a[i+1]);
	
	forn(i, n)
	{
		if (mn[i] >= a[i])
			res[i] = -1;
		else
		{
			int pos = upper_bound(mn, mn+i, a[i], greater<int>()) - mn;
			res[i] = i - pos - 1;
		}
	}
};