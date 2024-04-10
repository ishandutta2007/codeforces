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

const int maxn = 100005;

char s[maxn];
int n;

vector<int> solve1()
{
	scanf("%s", s);
	s[n] = '0';
	vector<int> ans;
	for (int i = 0; i < n; i++) if (s[i] != s[i + 1]) ans.pb(i + 1);
	return ans;
}

void solve()
{
	scanf("%d", &n);
	auto ta = solve1();
	auto tb = solve1();
	while (!tb.empty())
	{
		ta.pb(tb.back());
		tb.pop_back();
	}
	printf("%d", (int)ta.size());
	for (auto t : ta) printf(" %d", t);
	printf("\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}