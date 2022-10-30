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
const int maxn = 1e5 + 5, base = 1e9+7;

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

vector<pair<int, pii> > q;
vector<int> x;
map<int,int> sot;
vector<int> g[maxn];
map<int,int> szt[maxn];
vector<ll> t[maxn];

void add(int it, int i, int x)
{
	i++;
	while (i < t[it].size()){
		t[it][i] += x;
		i += i & (-i);
	}
}

ll sum(int it, int r)
{
	ll res = 0;
	r++;
	while (r > 0){
		res += t[it][r];
		r -= r & (-r);
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sz = 0;

	for (int i = 0; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		q.pb(mp(a, mp(b, c)));
		if (sot.find(c) == sot.end())
			sot[c] = sz++;
        c = sot[c];
		g[c].pb(b);
	}

	for (int i = 0; i < n; i++){
		sort(g[i].begin(), g[i].end());
		sz = 0;
		for (int j = 0; j < g[i].size(); j++){
			if (szt[i].count(g[i][j]) == 0){
				szt[i][g[i][j]] = sz++;
			}
		}

		t[i].resize(sz + 5);
	}

	for (int i = 0; i < q.size(); i++){
		int ty, tm, x;
		ty = q[i].f;
		tm = q[i].s.f;
		x = q[i].s.s;

		x = sot[x];
		tm = szt[x][tm];
		if (ty == 1){
			add(x, tm, 1);
		}
		if (ty == 2){
			add(x, tm, -1);
		}
		if (ty == 3){
			printf("%I64d\n", sum(x, tm));
		}
	}
	return 0;
}