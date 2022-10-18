//Krzysztof Boryczka
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

const int TRK=1e6;

ll n, a, b;
bool swp;

pair<ll, ll> check(ll tyle){
	for(ll i=a; i*i<=tyle && tyle/i>=b; i++){
		if(tyle%i==0) return {i, tyle/i};
	}
	return {-1, -1};
}

void ans(pair<ll, ll> odp){
	if(swp) swap(odp.st, odp.nd);
	cout<<odp.st*odp.nd<<ent;
	cout<<odp.st<<sp<<odp.nd<<ent;
}

void solve(){
	pair<ll, ll> ret;
	cin>>n>>a>>b;
	if(a>b){
		swp=1;
		swap(a, b);
	}
	n*=6;
	if(a*b>=n) return ans({a, b});
	for(ll i=n; i<=n+TRK; i++){
		ret=check(i);
		if(ret.st!=-1) return ans(ret);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}