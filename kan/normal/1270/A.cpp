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

int read(int k)
{
	int mx = -1;
	for (int i =0 ; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		mx = max(mx, x);
	}
	return mx;
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		int n;
		int k1, k2;
		scanf("%d%d%d", &n, &k1, &k2);
		int a = read(k1);
		int b = read(k2);
		printf("%s\n", (a > b ? "YES" : "NO"));
	}
    return 0;
}