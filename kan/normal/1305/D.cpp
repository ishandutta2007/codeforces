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

const int maxn = 1005;

vector<int> gr[maxn];
int deg[maxn];
bool was[maxn];
int n;

inline int ask(int a, int b)
{
	printf("? %d %d\n", a + 1, b + 1);
	fflush(stdout);
	int c;
	scanf("%d", &c);
	return c - 1;
}

inline void answer(int a)
{
	printf("! %d\n", a + 1);
	fflush(stdout);
	exit(0);
}

void del(int a)
{
	for (auto t : gr[a]) deg[t]--;
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
		deg[a]++;
		deg[b]++;
	}
	for (int i = 0; i < n; i++) was[i] = false;
	while (true)
	{
		int a = -1;
		for (int i = 0; i < n; i++) if (!was[i] && deg[i] == 1)
		{
			was[i] = true;
			a = i;
			break;
		}
		if (a == -1)
		{
			for (int i = 0; i < n; i++) if (!was[i] && deg[i] == 0)
			{
				was[i] = true;
				a = i;
				break;
			}
			assert(a != -1);
			answer(a);
		}
		int b = -1;
		for (int i = 0; i < n; i++) if (!was[i] && deg[i] == 1)
		{
			was[i] = true;
			b = i;
			break;
		}
		assert(b != -1);
		int c = ask(a, b);
		if (c == a) answer(a);
		if (c == b) answer(b);
		del(a);
		del(b);
	}
    return 0;
}