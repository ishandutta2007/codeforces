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

const int maxn = 205;
const int inf = maxn * 2;

int d[maxn];
int cnt[maxn];
queue<int> q;
bool inq[maxn];
int n, m;
vector<pair2<int>> gr[maxn];
int result[maxn];
int answer;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		if (c == 1)
		{
			gr[a].pb({b, 1});
			gr[b].pb({a, -1});
		} else
		{
			gr[a].pb({b, 1});
			gr[b].pb({a, 1});
		}
	}
	answer = -1;
	for (int start = 0; start < n; start++)
	{
		for (int i = 0; i < n; i++)
		{
			d[i] = inf;
			cnt[i] = 0;
			inq[i] = false;
		}
		while (!q.empty()) q.pop();
		d[start] = 0;
		q.push(start);
		inq[start] = true;
		bool ok = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cnt[cur]++;
			if (cnt[cur] > n)
			{
				ok = false;
				break;
			}
			inq[cur] = false;
			for (auto [to, cost] : gr[cur]) if (d[to] > d[cur] + cost)
			{
				d[to] = d[cur] + cost;
				if (!inq[to])
				{
					q.push(to);
					inq[to] = true;
				}
			}
		}
		if (!ok)
		{
			printf("NO\n");
			return 0;
		}
		//cout << start << endl;
		//for (int i =0 ; i < n; i++) cout << d[i] << ' ';
		//cout << endl;
		for (int i = 0; i < n; i++)
		{
			for (auto [to, cost] : gr[i])
			{
				if (cost == -1) ok &= d[to] == d[i] - 1;
				else ok &= (d[to] == d[i] - 1 || d[to] == d[i] + 1);
			}
		}
		if (!ok) continue;

		int maxd = *max_element(d, d + n) - *min_element(d, d + n);
		if (maxd > answer)
		{
			answer = maxd;
			int add = - *min_element(d, d + n);
			for (int i =0; i < n; i++) result[i] = d[i] + add;
		}
	}
	if (answer == -1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%d\n", answer);
	for (int i = 0; i <n; i++) printf("%d ", result[i]);
	printf("\n");
    return 0;
}