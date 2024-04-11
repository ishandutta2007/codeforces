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

const int N=1e5+5;

int lewy[N], prawy[N];
int t1[N], odp[N];
vector<pair<ii, int> > odc;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, ak=0, oucik=inf, otwwczesniej=0, otwteraz=0, zamkniete=0;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>t1[i];
	}
	sort(t1+1, t1+n+1);
	FOR(i, 1, n){
		prawy[i]=t1[i];
		lewy[i]=prawy[i-1];
	}
	lewy[n+1]=prawy[n];
	prawy[n+1]=1000000000;
	lewy[n+2]=prawy[n+1];
	lewy[n+3]=inf;
	FOR(i, 1, m){
		cin>>a>>b;
		if(a==1){
    		odc.pb({{a-1, -1}, b});
    		odc.pb({{b, 1}, a-1});
		}
		cin>>a;
	}
	odc.pb({{1000000001, 1}, 1000000001});
	sort(odc.begin(), odc.end());
	for(auto x: odc){
		while(x.st.st>lewy[ak+1] || (x.st.st==lewy[ak+1] && x.st.nd==1)){
			odp[ak]=otwwczesniej-zamkniete;
			otwwczesniej+=otwteraz-zamkniete;
			otwteraz=0;
			zamkniete=0;
			ak++;
		}
		if(x.st.nd==-1 && x.nd>prawy[ak]){ //otw
			otwteraz++;
		}
		else if(x.st.nd==1 && x.nd<=lewy[ak]){
			zamkniete++;
		}
		// cout<<x.st.st<<sp<<x.st.nd<<sp<<x.nd<<ent;
		// cout<<otwwczesniej<<sp<<otwteraz<<sp<<zamkniete<<ent;
		// cout<<ent;
	}
	// FOR(i, 1, n+1){
	// 	cout<<odp[i]<<ent;
	// }
	FOR(i, 1, n+1){
		oucik=min(oucik, i-1+odp[i]);
	}
	cout<<oucik<<ent;
	return 0;
}