#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;

vector<pair<int, int>> have[maxn];
vector<vector<int>> now;
vector<int> ids;
vector<int> primes;
int n, m;
int k[maxn];

void add(int id, int l, int p)
{
	vector<int> curp;
	for (auto t : primes)
	{
		if (l % t == 0) curp.pb(p % t);
		else curp.pb(-1);
	}
	now.pb(curp);
	ids.pb(id);
}

int find()
{
	int l = 0;
	vector<int> last(primes.size(), -1);
	int previd = -5;
	int answer = 0;
	for (int r = 0; r < (int)now.size(); r++)
	{
		if (previd != ids[r] - 1)
		{
			for (int i = 0; i < (int)primes.size(); i++)
			{
				if (now[r][i] == -1) last[i] = -1;
				else last[i] = r;
			}
			previd = ids[r];
			l = r;
			answer = max(answer, 1);
			continue;
		}
		previd = ids[r];
		for (int i = 0; i < (int)primes.size(); i++) if (now[r][i] != -1)
		{
			if (last[i] != -1)
			{
				if (now[r][i] != now[last[i]][i])
				{
					l = max(l, last[i] + 1);
				}
			}
			last[i] = r;
		}
		for (int i = 0; i < (int)primes.size(); i++) if (last[i] < l) last[i] = -1;
// 		cout << r << ' ' << l << endl;
		answer = max(answer, r - l + 1);
	}
	return answer;
}

int main()
{
	for (int i = 2; i <= 40; i++)
	{
		bool good = true;
// 		for (auto t : primes) if (i % t == 0) good = false;
		if (good) primes.pb(i);
	}
	cerr << primes.size() << endl;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 0; j < k[i]; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			have[x].pb({i, j});
		}
	}
	int cntbad = 0;
	int id = -1;
	for (int i = 0; i < m; i++) if (have[i].size() > 0)
	{
		cntbad ++;
		id = i;
	}
	if (cntbad == 1)
	{
		for (int i = 0; i < id; i++) printf("0\n");
		printf("%d\n", n);
// 		for (int i = 0; i < 100; i++) printf("0");
// 		printf("\n");
		for (int i = id + 1; i < m; i++) printf("0\n");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
// 		cout << "try " << i << endl;
		if (have[i].size() == 0)
		{
			printf("0\n");
			continue;
		}
		now.clear();
		ids.clear();
		for (auto t : have[i])
		{
			add(t.fi, k[t.fi], t.se);
		}
// 		for (auto t : have[i])
// 		{
// 			add(n + t.fi, k[t.fi], (t.se - 1 + k[t.fi]) % k[t.fi]);
// 		}
		int answer = find();
		printf("%d\n", answer);
	}
    return 0;
}