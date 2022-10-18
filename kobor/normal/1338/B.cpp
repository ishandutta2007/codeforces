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

vi G[N];
int n;
bool leaf[N];
int dpth[N];
int maks, mink=1;
int cnt[2];

void dfs(int v, int p){
	leaf[v]=1;
	dpth[v]=dpth[p]+1;
	for(auto &x: G[v]){
		if(x==p) continue;
		leaf[v]=0;
		dfs(x, v);
	}
}

void solve(){
	int a, b;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i, 1, n){
		if(SIZE(G[i])>1){
			dfs(i, i);
			break;
		}
	}
	FOR(i, 1, n) if(leaf[i]) cnt[dpth[i]%2]++;
	if(cnt[0] && cnt[1]) mink=3;
	FOR(i, 1, n){
		if(!leaf[i]) maks++;
		for(auto &x: G[i]) if(leaf[x]){
			maks++;
			break;
		}
	}
	cout<<mink<<sp<<maks-1<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // int tt; cin>>tt;
    // FOR(te, 1, tt)
	solve();
	return 0;
}