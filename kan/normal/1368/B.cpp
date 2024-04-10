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

const int LEN = 10;

const char s[LEN + 1] = "codeforces";

int cnt[LEN];

int main()
{
	ll k;
	scanf("%lld", &k);
	for (int i = 0; i < LEN; i++) cnt[i] = 1;
	ll cmul = 1;
	for (int z = 2; cmul < k; z++)
	{
		for (int t = 0; t < 10 && cmul < k; t++)
		{
			cmul = cmul / (z - 1) * z;
			cnt[t]++;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < cnt[i]; j++) printf("%c", s[i]);
	}
	printf("\n");
    return 0;
}