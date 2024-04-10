#include <bits/stdc++.h>
#include <windows.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e6 + 5, base = 1e9+7;

void bad(string mes = "NO"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
	string ans = "";
	while (x > 0){
		ans += char('0' + x % 2);
		x /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans.empty() ? "0" : ans;
}

template<typename T = int >
T input(){
	T ans = 0, m = 1;
	char c = ' ';
	while (c == ' ' || c == '\n')
		c = getchar();
	if (c == '-')
		m = -1,	c = getchar();
	while (c != ' ' && c != '\n')
		ans = ans * 10 + c - '0', c = getchar();
	return ans * m;
}

template<typename T>
T sqr(T x)
{
	return x * x;
}

int c1[maxn], c2[maxn];

vector<pair<int, char> > g[maxn];
int cnt0, cnt1;
vector<int> cmp;
bool flag1, flag2;

void dfs1(int v)
{
	if (c1[v] == 0)
		cnt0++;
	else
		cnt1++;
	cmp.pb(v);

	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i].f;
		char e = g[v][i].s;
		if (e == 'R'){
			if (c1[to] == -1)
				c1[to] = c1[v], dfs1(to);
            if (c1[to] != c1[v])
                flag1 = 1;
		} else {
			if (c1[to] == -1)
				c1[to] = !c1[v], dfs1(to);
            if (c1[to] == c1[v])
                flag1 = 1;
		}
	}
}

void dfs2(int v)
{
	if (c2[v] == 0)
		cnt0++;
	else
		cnt1++;
	cmp.pb(v);

	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i].f;
		char e = g[v][i].s;
		if (e == 'B'){
			if (c2[to] == -1)
				c2[to] = c2[v], dfs2(to);
            if (c2[to] != c2[v])
                flag2 = 1;
		} else {
			if (c2[to] == -1)
				c2[to] = !c2[v], dfs2(to);
            if (c2[to] == c2[v])
                flag2 = 1;
		}
	}
}

int main()
{
//    files1;

	int n, m;
	scanf("%d %d\n", &n, &m);
	memset(c1, -1, sizeof(c1));
    memset(c2, -1, sizeof(c2));

	for (int i = 0; i < m; i++){
		int f, t;
		char col;
		scanf("%d %d %c\n", &f, &t, &col);
		f--, t--;
		g[f].pb(mp(t, col));
		g[t].pb(mp(f, col));
	}

	vi ans1, ans2;
	for (int i = 0; i < n; i++){
		if (c1[i] == -1){
			cnt0 = cnt1 = 0;
			cmp.clear();
			c1[i] = 0;
			dfs1(i);
			int need = 0;
			if (cnt1 < cnt0)
				need = 1;
			for (int j = 0; j < cmp.size(); j++)
				if (c1[cmp[j]] == need)
					ans1.pb(cmp[j]);
            cnt0 = cnt1 = 0;
            cmp.clear();
            c2[i] = 0;
            dfs2(i);
            need = 0;
            if (cnt1 < cnt0)
                need = 1;
            for (int j = 0; j < cmp.size(); j++)
				if (c2[cmp[j]] == need)
					ans2.pb(cmp[j]);
		}
	}

    if (flag1 == 0 && (flag2 == 1 || ans1.size() < ans2.size())){
        	printf("%d\n", ans1.size());
        for (int i = 0; i < ans1.size(); i++)
            printf("%d ", ans1[i] + 1);
    }
    if (flag2 == 0 && (flag1 == 1 || ans2.size() < ans1.size())){
        	printf("%d\n", ans2.size());
        for (int i = 0; i < ans2.size(); i++)
            printf("%d ", ans2[i] + 1);
    }

    if (flag1 == 1 && flag2 == 1)
        bad("-1");
	return 0;
}