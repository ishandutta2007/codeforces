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

const int maxn = 100005;

int a[maxn];
ll sum[maxn];
int n;
set<int> bounds;
multiset<ll> sums;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
	bounds.insert(-1);
	bounds.insert(n);
	sums.insert(sum[n]);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		auto it = bounds.lower_bound(x);
		auto prv = *prev(it);
		int nxt = *it;
		sums.erase(sums.find(sum[nxt] - sum[prv + 1]));
		sums.insert(sum[nxt] - sum[x + 1]);
		sums.insert(sum[x] - sum[prv + 1]);
		bounds.insert(x);
		printf("%lld\n", *sums.rbegin());
	}
    return 0;
}