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
int sz[maxn];
ll ansdown[maxn];
int n;
ll answer;

void go(int cur, int pr)
{
	sz[cur] = 1;
	ansdown[cur] = 0;
	for (auto t : gr[cur]) if (t != pr)
	{
		go(t, cur);
		ansdown[cur] += ansdown[t];
		sz[cur] += sz[t];
	}
	ansdown[cur] += sz[cur];
}

void goup(int cur, int pr, ll fromup)
{
	ll curans = fromup;
	for (auto t : gr[cur]) if (t != pr)
	{
		curans += ansdown[t];
	}
	answer = max(answer, curans + n);
	for (auto t : gr[cur]) if (t != pr)
	{
		goup(t, cur, curans - ansdown[t] + (n - sz[t]));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i =0 ; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	go(0, -1);
	answer = 0;
	goup(0, -1, 0);
	cout << answer << endl;
    return 0;
}