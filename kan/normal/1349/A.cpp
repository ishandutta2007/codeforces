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

const int MX = 200005;

const int inf = 50;

bool notprime[MX];
int a[MX];
int cnt[MX];
int n;

int main()
{
	scanf("%d", &n);
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	//sort(a, a + n);
	ll answer = 1;
	for (int d = 2; d < MX; d++) if (!notprime[d])
	{
		for (ll j = (ll)d * d; j < MX; j += d) notprime[j] = true;
		
		int totcnt = 0;
		int minpw = inf;
		int minpw2 = inf;
		for (int z = d; z < MX; z += d)
		{
			totcnt += cnt[z];
			int pw = 0;
			int t = z;
			while (t % d == 0)
			{
				pw++;
				t /= d;
			}
			if (cnt[z] > 0)
			{
				if (pw < minpw)
				{
					minpw2 = minpw;
					minpw = pw;
				} else if (pw < minpw2)
				{
					minpw2 = pw;
				}
			}
			if (cnt[z] > 1)
			{
				if (pw < minpw)
				{
					minpw2 = minpw;
					minpw = pw;
				} else if (pw < minpw2)
				{
					minpw2 = pw;
				}
			}
		}
		if (totcnt < n)
		{
			minpw2 = minpw;
			minpw = 0;
		}
		if (totcnt < n - 1)
		{
			minpw2 = minpw;
			minpw = 0;
		}
		for (int t =0; t < minpw2; t++) answer *= d;
	}
	printf("%lld\n", answer);
    return 0;
}