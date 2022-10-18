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

int n;
int p[N];
bool zly[N], del[N], wyps, okno;
vi syny[N];

void solve(){
	cin>>n;
	FOR(i, 1, n){
		cin>>p[i]>>zly[i];
		if(p[i]!=-1) syny[p[i]].pb(i);
	}
	FOR(i, 1, n){
		okno=zly[i];
		for(auto &x: syny[i]) okno&=zly[x];
		if(okno){
			wyps=del[i]=1;
			cout<<i<<sp;
		}
	}
	if(!wyps) cout<<-1<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}