#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const int maxn = 200005;

vector<int> gr[maxn];
multiset<pair<int, int>> gr2[maxn];
bool was[maxn];
int ans[2 * maxn];
int answer[maxn];
int n, m;
int cnte, cntv;

bool go(int cur)
{
	cntv++;
	was[cur] = true;
	bool found = false;
	for (auto x : gr2[cur]) if (ans[x.second] == -1)
	{
		cnte++;
		if (was[x.first])
		{
			found = true;
			ans[x.second] = cur;
		} else
		{
			ans[x.second] = cur;
			if (!go(x.first)) ans[x.second] = x.first;
			else found = true;
		}	
	}
	return found;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			if (x < 0) gr[-x - 1].pb(-i - 1);
			else gr[x - 1].pb(i + 1);
		}
	}    
/*	for (int i = 0; i < m; i++)
	{
		cout << "from " << i << endl;
		for (auto t : gr[i]) cout << t << endl;
	}
	cout << "=============" << endl;*/
	for (int i = 0; i < m; i++) if (gr[i].size() != 0)
	{
		if (gr[i].size() == 1)
		{
			int a = abs(gr[i][0]) - 1;
			gr2[a].insert({a, i});
			gr2[a].insert({a, i + m});
		} else
		{
			int a = abs(gr[i][0]) - 1;
			int b = abs(gr[i][1]) - 1;
			if ((ll)gr[i][1] * gr[i][0] < 0)
			{
				gr2[a].insert({b, i});
				gr2[b].insert({a, i});
			} else
			{
				gr2[a].insert({b, i});
				gr2[b].insert({a, i});
				gr2[a].insert({b, i + m});
				gr2[b].insert({a, i + m});
			}
		}
	}
/*	for (int i =0 ; i < n; i++)
	{
		cout << "from " << i << endl;
		for (auto t : gr2[i]) cout << t.first << ' ' << t.se << endl;
	}*/
	for (int i = 0; i < 2 * m; i++) ans[i] = -1;
	for (int i = 0; i < n; i++) if (!was[i])
	{
		cnte = 0;
		cntv = 0;
		go(i);
		if (cnte < cntv)
		{
			printf("NO\n");
			return 0;
		}
	}	
//	for (int i = 0; i < 2 * m; i++) cout << ans[i] << endl;
	for (int i = 0; i < m; i++)
	{
		answer[i] = 1;
		for (auto x : gr[i]) if (abs(x) - 1 == ans[i])
		{
			if (x < 0) answer[i] = 0;
			else answer[i] = 1;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; i++) printf("%d", answer[i]);
	printf("\n");
    re 0;
}