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

int a[maxn];
int n;
int was[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
	//int ncycles = 0;
	vector<vector<int>> cycles;
	for (int i = 0; i < n; i++) if (!was[i])
	{
		int cur = i;
		while (!was[cur])
		{
			was[cur] = 1;
			cur = a[cur];
		}
		if (was[cur] == 1)
		{
			//cout << "cycle " << cur << endl;
			//ncycles++;
			cycles.pb({});
			while (was[cur] == 1)
			{
				was[cur] = 2;
				cycles.back().pb(cur);
				cur = a[cur];
			}
		}
		cur = i;
		while (was[cur] == 1)
		{
			was[cur] = 2;
			//cycles.back().pb(cur);
			cur = a[cur];
		}
	}
	int wh = -1;
	for (int i =0; i < (int)cycles.size(); i++) if (cycles[i].size() == 1)
	{
		wh = i;
	}
	int answer = 0;
	if (wh == -1)
	{
		a[cycles[0][0]] = cycles[0][0];
		answer++;
		wh = 0;
	}
	for (int i = 0; i < (int)cycles.size(); i++) if (i != wh)
	{
		a[cycles[i][0]] = cycles[wh][0];
		answer++;
	}
	printf("%d\n", answer);
	for (int i =0; i <n ; i++) printf("%d ", a[i] + 1);
    return 0;
}