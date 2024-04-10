#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 50005;

int a[maxn];
int n;
unordered_set<int> was;

bool can(int m)
{
	was.clear();
	for (int i = 0; i < n; i++)
	{
		int t = a[i];
		while (t > m) t /= 2;
		while (t > 0 && was.count(t)) t /= 2;
		if (t == 0) return false;
		was.insert(t);
	}
	return true;
}

void out(int m)
{
	was.clear();
	for (int i = 0; i < n; i++)
	{
		int t = a[i];
		while (t > m) t /= 2;
		while (t > 0 && was.count(t)) t /= 2;
		was.insert(t);
		printf("%d ", t);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &n);
// 	n = 50000;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
// 		a[i] = 900000000 + i;
	}
	int l = 0;
	int r = 1000000000;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (can(m)) r = m;
		else l = m;
	}
	out(r);
    return 0;
}