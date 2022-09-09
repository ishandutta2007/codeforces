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
int c[maxn];
int ans[maxn][2];
int n;
int answer;

void go(int cur, int pr)
{
	ans[cur][0] = 0;
	ans[cur][1] = 0;
	if (c[cur] < 2) ans[cur][c[cur]] = 1;
	for (auto t : gr[cur]) if (t != pr)
	{
		go(t, cur);
		answer = max(answer, ans[cur][0] + ans[t][1]);
		answer = max(answer, ans[cur][1] + ans[t][0]);
		answer = max(answer, ans[cur][0] + ans[t][0] - 1);
		answer = max(answer, ans[cur][1] + ans[t][1] - 1);
		ans[cur][0] = max(ans[cur][0], ans[t][0]);
		ans[cur][0] = max(ans[cur][0], ans[t][1] + (c[cur] == 0 ? 1 : -1));
		ans[cur][1] = max(ans[cur][1], ans[t][1]);
		ans[cur][1] = max(ans[cur][1], ans[t][0] + (c[cur] == 1 ? 1 : -1));
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) gr[i].clear();
	for (int i = 0; i < n; i++) scanf("%d", &c[i]), c[i] = 2 - c[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	answer = 1;
	go(0, -1);
	printf("%d\n", (answer + 2) / 2);
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