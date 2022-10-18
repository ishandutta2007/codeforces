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

ll t[(int)1e5+5];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, sum=0, ile=0, poz=0;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>t[i];
		sum+=t[i];
		poz=max(poz, t[i]);
	}
	poz++;
	sort(t+1, t+n+1);
	FORD(i, n, 1){
		ile+=max(1ll, poz-t[i-1]-1);
		poz=min(poz-1, t[i-1]+1);
		// cout<<t[i]<<sp<<ile<<sp<<poz<<ent;
	}
	cout<<sum-ile<<ent;
	return 0;
}