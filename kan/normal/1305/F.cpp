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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 200005;
const int MP = maxn * 1.5;

const int IT = 20;

ll a[maxn];
int b[maxn];
bool notprime[MP];
int n, m;
vector<ll> primes;
vector<pair<ll, ll>> curans;
set<ll> was;

void addprimes(ll x)
{
	if (x <= 0) return;
	for (ll y = 2; y * y <= x; y++) if (x % y == 0)
	{
		if (!was.count(y))
		{
			primes.pb(y);
			was.insert(y);
		}
		while (x % y == 0) x /= y;
	}
	if (x > 1)
	{
		if (!was.count(x))
		{
			primes.pb(x);
			was.insert(x);
		}
	}
}

int main()
{
	unsigned long long seed = 0;
	string ss = "sdgkljhg34togiunsdcnuow3gheoifiudsfbadsfjywafbiasopfo8ysbdv    		sdv   safd  		sdfasfj93fnre";
	unsigned long long hst = 239;
	for (auto t : ss) seed = seed * hst + t;
	rng.seed(seed);
	for (int i = 2; i < MP; i++) if (!notprime[i])
	{
		primes.pb(i);
		for (ll j = (ll)i * i; j < MP; j += i) notprime[j] = true;
	}
	scanf("%d", &n);
	//n = 200000;
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	//for (int i = 0; i < n; i++) a[i] = rng() % ((ll)1e12) + 1;
	shuffle(a, a + n, rng);
	for (int i = 0; i < IT; i++)
	{
		int p = rng() % n;
		addprimes(a[p]);
		addprimes(a[p] - 1);
		addprimes(a[p] + 1);
	}
	for (auto t : primes) curans.pb({t, 0});
	sort(a, a + n);
	b[0] = 1;
	int m = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[m - 1])
		{
			a[m++] = a[i];
			b[m - 1] = 1;
		} else b[m - 1]++;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < (int)curans.size(); j++)
		{
			ll r = curans[j].fi - a[i] % curans[j].fi;
			if (a[i] >= curans[j].fi) r = min(r, curans[j].fi - r);
			curans[j].se += (ll)r * b[i];
			if (curans[j].se > n - 1)
			{
				swap(curans[j], curans.back());
				curans.pop_back();
				j--;
			}
		}
		//cout << i << ' ' << (int)curans.size() << endl;
	}
	int answer = n;
	for (auto t : curans) answer = min(answer, (int)t.se);
	cout << answer << endl;
    return 0;
}