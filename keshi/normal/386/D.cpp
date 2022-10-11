//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 80;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b, c, d, dis[maxn][maxn][maxn], da, db, dc;

string s[maxn];

vector<ll> g[maxn][26];

vector<pll> ans;

pair<ll, pll> p, par[maxn][maxn][maxn];

pll op[maxn][maxn][maxn];

queue<pair<ll, pll> > q;

pair<ll, pll> fix(pair<ll, pll> x){
	return {min(x.F, min(x.S.F, x.S.S)), {x.F + x.S.F + x.S.S - min(x.F, min(x.S.F, x.S.S)) - max(x.F, max(x.S.F, x.S.S)), max(x.F, max(x.S.F, x.S.S))}};
}

ll cal(pair<ll, pll> x){
	x = fix(x);
	return dis[x.F][x.S.F][x.S.S];
}

void se(pair<ll, pll> x, ll e){
	x = fix(x);
	dis[x.F][x.S.F][x.S.S] = e;
	return;
}

int main(){
	fast_io;
	
	cin >> n >> da >> db >> dc;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < n; j++){
			if(i != j){
				g[i][s[i][j] - 'a'].pb(j);
			}
			for(ll k = 0; k < n; k++){
				dis[i][j][k] = inf;
			}
		}
	}
	a = --da;
	b = --db;
	c = --dc;
	if(a > b){
		swap(a, b);
	}
	if(b > c){
		swap(b, c);
	}
	if(a > b){
		swap(a, b);
	}
	da = a;db = b; dc = c;
	q.push({a, {b, c}});
	dis[a][b][c] = 0;
	
	while(!q.empty()){
		a = q.front().F;
		b = q.front().S.F;
		c = q.front().S.S;
		q.pop();
		for(ll i = 0; i < g[a][s[b][c] - 'a'].size(); i++){
			d = g[a][s[b][c] - 'a'][i];
			p = fix({d, {b, c}});
			if(d != a && d != b && d != c && dis[p.F][p.S.F][p.S.S] > dis[a][b][c] + 1){
				dis[p.F][p.S.F][p.S.S] = dis[a][b][c] + 1;
				par[p.F][p.S.F][p.S.S] = {a, {b, c}};
				op[p.F][p.S.F][p.S.S] = {a, d};
				q.push(p);
			}
		}
		for(ll i = 0; i < g[b][s[a][c] - 'a'].size(); i++){
			d = g[b][s[a][c] - 'a'][i];
			p = fix({d, {a, c}});
			if(d != a && d != b && d != c && dis[p.F][p.S.F][p.S.S] > dis[a][b][c] + 1){
				dis[p.F][p.S.F][p.S.S] = dis[a][b][c] + 1;
				dis[p.F][p.S.F][p.S.S] = dis[a][b][c] + 1;
				par[p.F][p.S.F][p.S.S] = {a, {b, c}};
				op[p.F][p.S.F][p.S.S] = {b, d};
				q.push(p);
			}
		}
		for(ll i = 0; i < g[c][s[a][b] - 'a'].size(); i++){
			d = g[c][s[a][b] - 'a'][i];
			p = fix({d, {a, b}});
			if(d != a && d != b && d != c && dis[p.F][p.S.F][p.S.S] > dis[a][b][c] + 1){
				dis[p.F][p.S.F][p.S.S] = dis[a][b][c] + 1;
				dis[p.F][p.S.F][p.S.S] = dis[a][b][c] + 1;
				par[p.F][p.S.F][p.S.S] = {a, {b, c}};
				op[p.F][p.S.F][p.S.S] = {c, d};
				q.push(p);
			}
		}
	}
	
	if(dis[0][1][2] == inf){
		cout << -1;
		return 0;
	}
	
	p = {0, {1, 2}};
	
	while(p.F != da || p.S.F != db || p.S.S != dc){
		ans.pb(op[p.F][p.S.F][p.S.S]);
		p = par[p.F][p.S.F][p.S.S];
	}
	
	cout << dis[0][1][2] << endl;
	
	if(ans.size() == 0) return 0;
	
	for(ll i = ans.size() - 1; i > -1; i--){
		cout << ans[i].F + 1 << " " << ans[i].S + 1 << endl;
	}
	
	return 0;
}