#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
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

inline void put(bool ok)
{
	if (!ok) printf("Tidak ");
	else printf("Ya ");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int sgn = (a + b) % 2;
		bool cang1 = (a + d) > 0;
		bool canl1 = (c + b) > 0;
		if (sgn)
		{
			put(cang1); put(canl1);
			put(false); put(false);
		} else
		{
			put(false); put(false);
			put(canl1); put(cang1);
		}
		printf("\n");
	}
    return 0;
}