#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int main()
{
	int n;
	scanf("%d", &n);
	int curmax = 0;
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		int a = curmax + b;
		printf("%d ", a);
		curmax = max(curmax, a);
	}
	printf("\n");
    return 0;
}