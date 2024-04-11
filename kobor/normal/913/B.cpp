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

const int N=1e3+5;

int n;
vi G[N];

void solve(){
	int a;
	cin>>n;
	FOR(i, 2, n){
		cin>>a;
		G[a].pb(i);
	}
	FOR(i, 1, n){
		if(!SIZE(G[i]) && i!=1) continue;
		int ile=0;
		for(auto &x: G[i]){
			ile+=SIZE(G[x])==0;
		}
		if(ile<3){
			cout<<"No"<<ent;
			return;
		}
	}
	cout<<"Yes"<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}