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

map<ll, ll> cost;

ll query(ll v, ll u){
	ll ret=0;
	while(v!=u){
		if(v>u) swap(v, u);
		ret+=cost[u];
		u>>=1;
	}
	return ret;
}

void add(ll v, ll u, ll val){
	while(v!=u){
		if(v>u) swap(v, u);
		cost[u]+=val;
		u>>=1;
	}
}

void solve(){
	int n;
	cin>>n;
	FOR(i, 1, n){
		int type;
		ll v, u, w;
		cin>>type>>v>>u;
		if(type==1){
			cin>>w;
			add(v, u, w);
		}
		else cout<<query(v, u)<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}