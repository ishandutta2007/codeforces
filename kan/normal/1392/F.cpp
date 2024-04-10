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

const int maxn = 1000'006;

ll h[maxn];
vector<int> zeros;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
	zeros.clear();
	ll h0 = h[0];
	for (int i = 1; i < n; i++)
	{
		ll hlast = h0 + i - 1 - zeros.size();
		while (true)
		{
			assert(h[i] >= hlast);
			if (h[i] == hlast)
			{
				zeros.pb(i);
				break;
			}
			if (!zeros.empty())
			{
				int need = i - zeros.back();
				if (h[i] - need >= hlast + 1)
				{
					h[i] -= need;
					hlast++;
					zeros.pop_back();
					continue;
				} else
				{
					ll have = h[i] - (hlast + 1);
					zeros.back() += have;
					break;
				}
			} else
			{
				// h[i] - its * i >= hlast + its
				// its * (i + 1) <= h[i] - hlast
				ll its = (h[i] - hlast) / (i + 1);
				h0 += its;
				hlast += its;
				h[i] -= its * i;
				assert(h[i] >= hlast);
				if (h[i] == hlast)
				{
					zeros.pb(i);
					break;
				} else if (h[i] == hlast + 1) break;
				int have = h[i] - (hlast + 1);
				h0++;
				zeros.pb(have);
				break;
			}
		}
	}
	int cur = 0;
	h[0] = h0;
	for (int i = 1; i < n; i++)
	{
		h[i] = h[i - 1] + 1;
		if (cur < (int)zeros.size() && zeros[cur] == i)
		{
			h[i]--;
			cur++;
		}
	}
	for (int i =0; i < n; i++) printf("%lld ", h[i]);
	printf("\n");
    return 0;
}