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

const int maxn = 10004;
const int maxt = 1003;

const int inf = 2 * maxn;

int d[maxn][maxt];
int x[maxn];
deque<int> q;
int w, n;
int G, R;

int main()
{
	scanf("%d%d", &w, &n);
	//w = 1000000;
	//n = 10000;
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	//for (int i = 0; i < n - 1; i++) x[i] = i * 100;
	//x[n - 1] = w;
	sort(x, x + n);
	scanf("%d%d", &G, &R);
	//G = 1000;
	//R = 1000;
	for (int i = 0; i < n; i++)
	{
		for (int t =0 ; t < G; t++) d[i][t] = inf;
	}
	d[0][0] = 0;
	q.push_back(0 * G + 0);
	int answer = inf * (G + R);
	while (!q.empty())
	{
		auto curst = q.front();
		q.pop_front();
		int cur, curt;
		curt = curst % G;
		cur = curst / G;
		int curd = d[cur][curt];
		//cout << cur << ' ' << curt << ' ' << curd << endl;
		if (cur == n - 1)
		{
			int add = 0;
			if (curt == 0) add = -R;
			answer = min(answer, curd * (G + R) + curt + add);
		}
		if (cur + 1 < n)
		{
			int nt = curt + (x[cur + 1] - x[cur]);
			int nd = curd;
			int add = 0;
			if (nt <= G)
			{
				if (nt == G)
				{
					add = 1;
					nt = 0;
				}
				if (d[cur + 1][nt] > nd + add)
				{
					d[cur + 1][nt] = nd + add;
					if (add) q.push_back((cur + 1) * G + nt);
					else q.push_front((cur + 1) * G + nt);
				}
			}
		}
		if (cur > 0)
		{
			int nt = curt + (x[cur] - x[cur - 1]);
			int nd = curd;
			int add = 0;
			if (nt <= G)
			{
				if (nt == G)
				{
					add = 1;
					nt = 0;
				}
				if (d[cur - 1][nt] > nd + add)
				{
					d[cur - 1][nt] = nd + add;
					if (add) q.push_back((cur - 1) * G + nt);
					else q.push_front((cur - 1) * G + nt);
				}
			}
		}
	}
	if (answer == inf * (G + R)) answer = -1;
	printf("%d\n", answer);
    return 0;
}