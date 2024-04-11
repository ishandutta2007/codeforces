#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VPII;

const LD EPS=10e-9;
const int MOD=1000000007;
const int PMOD1=606574021;
const int PMOD2=606574027;
const int INF=1000000009;
const LL LLINF=1000000000000000009;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//END OF TEMPLATE

unordered_map<string, int> M;
long long t[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m, h, pom;
	LL pom2, wyn=0;
	VI odp;
	string s;
	cin>>n>>k>>m;
	FOR(i, 1, n){
		cin>>s;
		M[s]=i;
	}
	FOR(i, 1, n){
		cin>>t[i];
	}
	FOR(i, 1, k){
		cin>>h;
		odp.clear();
		pom2=LLINF;
		FOR(j, 1, h){
			cin>>pom;
			pom2=min(pom2, t[pom]);
			odp.PB(pom);
		}
		FOR(j, 0, SIZE(odp)-1){
			t[odp[j]]=pom2;
		}
	}
	FOR(i, 1, m){
		cin>>s;
		wyn+=t[M[s]];
	}
	cout<<wyn<<'\n';
	return 0;
}