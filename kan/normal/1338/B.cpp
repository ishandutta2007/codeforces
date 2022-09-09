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

vector<int> gr[maxn];
int cnt[maxn];
int cntd2 = 0;
int answer;
bool alleven;
int n;

void go(int cur, int pr, int curd)
{
	if (pr != -1 && gr[cur].size() == 1)
	{
		cnt[pr]++;
		if (curd % 2 != 0) alleven = false;
		if (curd == 2) cntd2++;
		return;
	}
	for (auto t : gr[cur]) if (t != pr)
	{
		go(t, cur, curd + 1);
	}
	if (curd != 1) answer -= max(0, cnt[cur] - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	alleven = true;
	answer = n - 1;
	for (int i = 0; i < n; i++) if (gr[i].size() == 1)
	{
		go(i, -1, 0);
		break;
	}
	answer -= cntd2;
	if (alleven) printf("%d ", 1);
	else printf("%d ", 3);
	printf("%d\n", answer);
    return 0;
}