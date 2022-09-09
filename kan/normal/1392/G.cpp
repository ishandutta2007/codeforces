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

const int maxn = 1000'006;
const int maxmask = 1 << 20;
const int inf = 55;

int a[maxn], b[maxn];
int dist[maxmask], from[maxmask];
int n, m, k;
vector<int> ma, mb;
char s[100];
queue<int> q;
int nmasks;
int suffma[maxn], suffmb[maxn];
int wh[maxn], p[maxn];

vector<int> readmask()
{
	scanf("%s", s);
	vector<int> ans;
	for (int i =0; i < k; i++) ans.pb(s[i] - '0');
	return ans;
}

void addfinal(int mask, int f)
{
	if (dist[mask] == 0) return;
	dist[mask] = 0;
	from[mask] = f;
	q.push(mask);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i =0; i < k; i++)
		{
			int nxt = cur ^ (1 << i);
			if (dist[nxt] > dist[cur] + 1)
			{
				dist[nxt] = dist[cur] + 1;
				from[nxt] = from[cur];
				q.push(nxt);
			}
		}
	}
}

string str(int x)
{
	string ans;
	for (int i =0; i < k; i++) ans += '0' + ((x >> i) & 1);
	return ans;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	ma = readmask();
	mb = readmask();
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		a[i]--, b[i]--;
	}
	nmasks = 1 << k;
	for (int i = 0; i < nmasks; i++) dist[i] = inf;
	for (int i = 0; i < k; i++) wh[i] = i;
	for (int i = 0; i < k; i++) p[i] = i;
	for (int i = 0; i < k; i++) suffmb[n] |= (mb[i] << i);
	pair<int, pair2<int>> answer = {-1, {-1, -1}};
	for (int i = n - 1; i >= 0; i--)
	{
		swap(wh[a[i]], wh[b[i]]);
		swap(p[a[i]], p[b[i]]);
		for (int j = 0; j < k; j++) suffma[i] |= (ma[j] << wh[j]);
		//for (int j = 0; j < k; j++) suffmb[i] |= (mb[p[j]] << j);
		for (int j = 0; j < k; j++) suffmb[i] |= (mb[j] << wh[j]);
		
		//cout << i << ' ' << str(suffma[i]) << ' ' << str(suffmb[i]) << endl;
		
		if (i + m <= n)
		{
			addfinal(suffmb[i + m], i + m);
			//cout << i << ' ' << str(suffma[i]) << ' ' << dist[suffma[i]] << endl;
			answer = max(answer, {k - dist[suffma[i]], {i, from[suffma[i]] - 1}});
		}
	}
	printf("%d\n", answer.fi);
	printf("%d %d\n", answer.se.fi + 1, answer.se.se + 1);
	
    return 0;
}