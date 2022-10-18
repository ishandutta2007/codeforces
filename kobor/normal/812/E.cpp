//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int N=1e5+5;

map<int, int> blue, red;
vi G[N];
int n, t[N];
ll ans;
int blu, re;

int dfs(int v){
	int xd=0;
	for(auto &x: G[v]) xd=dfs(x);
	if(xd&1) red[t[v]]++, blu++;
	else blue[t[v]]++, re++;
	return xd+1;
}

void solve(){
	int a;
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 2, n){
		cin>>a;
		G[a].pb(i);
	}
	dfs(1);
	int bluexor=0;
	for(auto &x: blue) if(x.nd&1) bluexor^=x.st;
	if(bluexor == 0){
		ans+=(ll)blu*(blu-1)/2;
		ans+=(ll)re*(re-1)/2;
	}
	for(auto &x: red) ans+=(ll)blue[x.st^bluexor]*x.nd;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}