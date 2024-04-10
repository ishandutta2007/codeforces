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

const int maxn = 305;
const int maxd = 100005;
const int inf = 1e9;

vector<int> d;
int l[maxn], c[maxn];
int ans[maxd];
int n;

void upd(int g, int c)
{
	int wh = lower_bound(d.begin(), d.end(), g) - d.begin();
	ans[wh] = min(ans[wh], c);
}

void gendivs(int x)
{
	for (int i = 1; i * i <= x; i++) if (x % i == 0)
	{
		d.push_back(i);
		d.push_back(x / i);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &l[i]);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) gendivs(l[i]);
	d.push_back(0);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());
	for (int i = 0; i < (int)d.size(); i++) ans[i] = inf;
	ans[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)d.size(); j++) upd(__gcd(d[j], l[i]), ans[j] + c[i]);
	}
	if (ans[1] >= inf)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans[1]);
	return 0;
}