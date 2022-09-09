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
int n, k;
vector<int> series;

void solve()
{
	scanf("%d%d", &n, &k);
	series.clear();
	int cur = k + 5;
	scanf("%s", s);
	int score = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			cur++;
		} else
		{
			score += (cur > 0 ? 1 : 2);
			if (cur > 0) series.pb(cur);
			cur = 0;
		}
	}
	if (cur == k + 5 + n)
	{
		printf("%d\n", max(0, 2 * min(k, n) - 1));
		return;
	}
	sort(all(series));
	for (auto t : series) if (k >= t)
	{
		score += 2 * t;
		score++;
		k -= t;
	}
	score += 2 * k;
	score = min(score, 2 * n - 1);
	printf("%d\n", score);
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