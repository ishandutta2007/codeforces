#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 2000006;

int n, NQ;
int a[maxn];
bool was[maxn];
int st[maxn];
int needfind;
bool found;
// vector<int> gr[maxn];
int nexte[maxn], edge[maxn], first[maxn];

void go(int cur, int d)
{
	if (was[cur] || found) return;
	was[cur] = true;
	if (d >= needfind && st[d - needfind] >= cur + n) found = true;
	st[d] = cur;
	for (int e = first[cur]; e != -1; e = nexte[e]) go(edge[e], d + 1);
}

int main()
{
	scanf("%d%d", &n, &NQ);
// 	n = 1000000;
// 	NQ = 50;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
// 	for (int i = 0; i < n; i++) a[i] = abs((rand() << 15) | rand()) + 1;
	for (int i = 0; i < n; i++) a[i + n] = a[i];
	ll total = 0;
	for (int i = 0; i < n; i++) total += a[i];
	for (int Q = 0; Q < NQ; Q++)
	{
// 		cerr << Q << endl;
		ll B;
		scanf(LLD, &B);
// 		B = 4e10 + abs((rand() << 15) | rand()) + 1;
		if (B >= total)
		{
			printf("%d\n", 1);
			continue;
		}
		for (int i = 0; i <= 2 * n; i++) first[i] = -1;
		int cur = 0;
		ll cursum = 0;
		int ke = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			while (cur < 2 * n && cursum + a[cur] <= B)
			{
				cursum += a[cur];
				cur++;
			}
			nexte[ke] = first[cur];
			first[cur] = ke;
			edge[ke] = i;
			ke++;
			cursum -= a[i];
		}
		cur = 1;
		cursum = 0;
		for (int i = 0; i < n; i++)
		{
			if (cursum + a[i] > B)
			{
				cursum = 0;
				cur++;
			}
			cursum += a[i];
		}
		needfind = cur - 1;
		for (int i = 0; i <= 2 * n; i++) was[i] = false;
		found = false;
		for (int i = 2 * n; i >= 0; i--) go(i, 0);
		if (found) printf("%d\n", needfind);
		else printf("%d\n", needfind + 1);
	}
	cerr << clock() << endl;
	return 0;
}