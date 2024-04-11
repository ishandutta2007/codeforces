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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int n, m;
ll maks, a;
vector<ll> comp[200010];
ll loc[200010];
ll odp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i, 0, n-1){
		cin>>m;
		FOR(j, 1, m){
			cin>>a;
			comp[i].pb(a);
			loc[i]=max(loc[i], a);
		}
		maks=max(maks, loc[i]);
	}
	FOR(i, 0, n-1){
		odp+=(ll)SIZE(comp[i])*(maks-loc[i]);
	}
	cout<<odp<<ent;
	return 0;
}