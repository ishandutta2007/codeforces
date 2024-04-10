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

const int maxn = 200005;

vector<int> gr[maxn];
vector<int> all;
int n, k;

int go(int cur, int pr, int curd)
{
	int cursz = 1;
	for (auto t : gr[cur]) if (t != pr)
	{
		cursz += go(t, cur, curd + 1);
	}
	all.pb({curd - (cursz - 1)});
	return cursz;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i =0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	go(0, -1, 0);
	sort(all(all));
	reverse(all(all));
	ll answer = accumulate(all.begin(), all.begin() + k, 0LL);
	printf("%lld\n", answer);
    return 0;
}