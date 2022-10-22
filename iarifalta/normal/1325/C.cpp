#include <bits/stdc++.h>
#define pb push_back
#define ll unsigned long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 1e5 + 1;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll n;

vector<ll> g[N];

bool lis[N];

ll rst[N];
ll r;

ll amir[N];

map<pill, ll > smt;

void dfs(ll v = r ,ll p = -1,ll d = 0){
	rst[v] = d;
	for(auto u : g[v]){
		if(u != p){
			pill alta = {min(v,u) , max(v,u)};
			amir[u] = smt[alta]; 
			dfs(u , v , d + 1);
		}
	}
}

ll answ[N];
vector<pill> mvl;

bool c[N];


void bfs(){
	ll num = 1;
	queue<ll> x;
	if(mvl.size() > 2){
		for(int i = 0 ; i < 3 ; i++){
			answ[amir[mvl[i].s]] = num++;
		}
	}
	for(int i = 1 ; i <= n - 1; i++)	
		if(answ[i])
			cout << answ[i] - 1 << '\n';
		else
			cout << (num++) - 1 << '\n';
}

int main() {
    speed;
    cin >> n; 
    for(int i = 1; i < n ; i++){
    	ll x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    	smt.insert({{min(x,y) , max(x , y)}, i});
    	
    	if(g[x].size() > 1)
			lis[x] = 1;
		if(g[y].size() > 1)
			lis[y] = 1; 
	}
	vector<ll> pp;
	for(int i = 1 ; i <= n ; i++){
		if(lis[i])
			r = i;	
		else
			pp.pb(i);
	}
	dfs(r);
	for(auto u : pp) {
		mvl.pb({rst[u], u});
	}
	sort(mvl.begin(),mvl.end());
	bfs();
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/