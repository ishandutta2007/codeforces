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

const int m = 20;

const int PLUS = 0;
const int XOR = 1;

const char chr[3] = "+^";

vector<array<ll, 3>> ops;
set<ll> have;

int solve2(ll n, ll divby)
{
	for (int mask = 0; mask < (1 << m); mask++)
	{
		ll x = 1;
		for (int i = 0; i < m; i++) if (mask & (1 << i))
		{
			x ^= (n << i);
		}
		if (x % divby == 0) return mask;
	}
	return -1;
}

void printops()
{
	printf("%d\n", (int)ops.size());
	for (auto t : ops)
	{
		assert(t[0] <= 2e18);
		assert(t[1] <= 2e18);
		assert(have.count(t[0]));
		assert(have.count(t[1]));
		if (t[2] == PLUS) have.insert(t[0] + t[1]);
		else have.insert(t[0] ^ t[1]);
		printf("%lld %c %lld\n", t[0], chr[t[2]], t[1]);
	}
	assert(have.count(1));
}

void solve(ll n)
{
	have.clear();
	have.insert(n);
	ops.clear();
	ll cur = 0;
	bool found = false;
	for (int i = 0; i < 20; i++)
	{
		if (i != 0) ops.pb({cur, (n << i), XOR});
		cur ^= (n << i);
		int res = solve2(cur, n);
		if (res != -1)
		{
			found = true;
			//cout << "found " << n << ' ' << cur << ' ' << res << endl;
			int mx = 0;
			for (int i = 0; i < m; i++) if (res & (1 << i))
			{
				mx = i;
			}
			for (int i = 0; i < mx; i++) ops.pb({(cur << i), (cur << i), PLUS});
			bool first = true;
			ll cur2 = 0;
			for (int i = 0; i <= mx; i++) if (res & (1 << i))
			{
				if (!first) ops.pb({(cur << i), cur2, XOR});
				cur2 ^= (cur << i);
				first = false;
			}
			cur2 ^= 1;
			assert(cur2 % n == 0);
			ll x = cur2 / n;
			
			//cout << x << endl;

			mx = 0;
			for (int i = 0; i < 60; i++) if (x & (1LL << i))
			{
				mx = i;
			}
			//cout << mx << endl;
			for (int j = i; j < mx; j++)
			{
				ops.pb({(n << j), (n << j), PLUS});
			}
			//cout << mx << endl;
			first = true;
			ll cur3 = 0;
			for (int i = 0; i <= mx; i++) if (x & (1LL << i))
			{
				if (!first) ops.pb({(n << i), cur3, PLUS});
				cur3 += (n << i);
				first = false;
			}
			ops.pb({(cur2 ^ 1), cur3, XOR});
			printops();
			break;
		}
		ops.pb({(n << i), (n << i), PLUS});
	}
	assert(found);
}

int main()
{
	//solve(16389);
	//int x = 8193;
	//int y = (2 * x) ^ x;
	//cout << "y = " << y << endl;
	//solve(y);
	//for (int i : {8193, 16385, 32769, 32771, 49155, 65537, 65539})
	//{
		//solve(i);
	//}
	//for (int k = 1; k <= 20; k++)
	//{
		//for (int i = 1; i <= 20; i += 2)
		//{
			//int x = (1 << k) + i;
			//if (x <= 999'999) solve(x);
			//cout << x << " ok " << endl;
		//}
	//}
	//solve(8193);
	//for (int i = 3; i <= 9999; i += 2)
	//{
		//solve(i);
		////if ((i - 1) % 1000 == 0) cout << i << " ok" << endl;
	//}
	int n;
	scanf("%d", &n);
	solve(n);
    return 0;
}