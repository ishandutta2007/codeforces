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
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define next next_sdf
#define prev prev_sdf
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;


template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> int sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int maxn = 505;

int n;
int m;
int gr[maxn][maxn];
bool was[maxn];
char ans[maxn];

void go(int cur, int c)
{
	if (was[cur])
	{
		if (ans[cur] == 'a' + c) return;
		printf("No\n");
		exit(0);
	}
	was[cur] = true;
	ans[cur] = 'a' + c;
	for (int i = 0; i < n; i++) if (gr[cur][i]) go(i, 2 - c);
}

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a][b] = 1;
		gr[b][a] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) if (i != j) gr[i][j] = 1 - gr[i][j];
	}
	for (int i = 0; i < n; i++) if (!was[i])
	{
		bool was = false;
		for (int j = 0; j < n; j++) was |= gr[i][j];
		if (!was) ans[i] = 'b';
		else go(i, 0);
	}
	for (int i = 0; i < n; i++) if (ans[i] == 'a')
	{
		for (int j = 0; j < n; j++) if (ans[j] == 'c')
		{
			if (!gr[i][j])
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	ans[n] = '\0';
	printf("%s\n", ans);
	return 0;
}