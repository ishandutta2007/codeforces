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

ll nast(ll v){
	if(v==0) return 0;
	int zer=-1;
	ll pom=v;
	while(pom){
		zer++;
		pom>>=1;
	}
	if(zer%2 == 0) return nast(v ^ (1ll<<zer)) ^ (1ll<<(zer+1));	//01
	if((1ll << (zer-1)) & v) return nast(v ^ (1ll<<zer) ^ (1ll<<(zer-1))) ^ (1ll<<(zer-1));
	return nast(v ^ (1ll<<zer)) ^ (1ll<<(zer)) ^ (1ll<<(zer-1));
}

void solve(){
	ll n, akt=1, n2, val;
	cin>>n;
	while(akt<=n) akt*=4;
	akt/=4;
	n2 = n-akt;
	val = akt+n2/3;
	if(n%3 == 1) cout<<val;
	else if(n%3 == 2) cout<<nast(val);
	else cout<<nast(nast(val));
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt)
	solve();
	return 0;
}