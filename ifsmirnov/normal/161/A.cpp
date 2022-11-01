#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 100500;

int x, y;
int n, m;
pii a[maxn], b[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	forn(i, n)
	{
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	forn(i, m)
	{
		scanf("%d", &b[i].fi);
		b[i].se = i;
	}
	sort(a, a+n);
	sort(b, b+m);
	
	vector<pii> res;
	
	for (int i = 0, j = 0; i < n && j < m; i++)
	{
		while (j < m && b[j].fi < a[i].fi - x)
			++j;
		if (j < m && b[j].fi <= a[i].fi + y)
		{
			res.pb(mp(a[i].se, b[j].se));
			++j;
		}
	}
	
	printf("%d\n", (int)res.size());
	forn(i, res.size())
		printf("%d %d\n", res[i].fi+1, res[i].se+1);
	
	return 0;
}