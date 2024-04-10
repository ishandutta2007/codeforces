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

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair2<int>> answer;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		answer.pb({i, 0});
	}
	for (int i = 0; i < n; i++)
	{
		answer.pb({2 * i, 1});
		answer.pb({2 * i, 2});
		answer.pb({2 * i, -1});
		answer.pb({2 * i, -2});
	}
	answer.pb({-1, 0});
	answer.pb({-2, 0});
	answer.pb({2 * n - 1, 0});
	answer.pb({2 * n, 0});
	for (int i = 0; i + 1< n; i += 2)
	{
		answer.pb({2 * i + 1, 2});
	}
	for (int i = 1; i + 1 < n; i += 2)
	{
		answer.pb({2 * i + 1, -2});
	}
	answer.pb({-2, -1});
	answer.pb({-2, -2});
	answer.pb({-1, -2});
	if (n % 2 == 0)
	{
		answer.pb({2 * n - 1, -2});
		answer.pb({2 * n, -2});
		answer.pb({2 * n, -1});
	} else
	{
		answer.pb({2 * n - 1, 2});
		answer.pb({2 * n, 2});
		answer.pb({2 * n, 1});
	}
	sort(all(answer));
	printf("%d\n", (int)answer.size());
	for (auto t : answer) printf("%d %d\n", t.fi, t.se);
    return 0;
}