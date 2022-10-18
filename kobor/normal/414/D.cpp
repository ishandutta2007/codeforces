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
//END OF TEMPLATE

const int N=1e5+5;

int n, k, p, sumka, ans;
int ile[N], pref[N];
vi G[N];

void dfs(int v, int par, int dpt){
	ile[dpt]++;
	for(auto &x: G[v]){
		if(x==par) continue;
		dfs(x, v, dpt+1);
	}
}

int suma(int a, int b){
	return pref[b]-pref[a-1];
}

void solve(){
	int a, b;
	cin>>n>>k>>p;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, 1, 2);
	ile[2]--;
	FOR(i, 1, n+1) pref[i]=ile[i]+pref[i-1];
	int j=1;
	FOR(i, 2, n+1){
		sumka+=suma(j, i-1);
		while(sumka>p){
			sumka-=(i-j)*ile[j];
			j++;
		}
		ans=max(ans, suma(j, i)+min((p-sumka)/(i-j+1), ile[j-1]));
	}
	cout<<min(ans, k)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}