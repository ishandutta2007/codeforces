//Krzysztof Boryczka
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

int t[110];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, s, a, b, odp=-1;
	cin>>n>>s;
	FOR(i, 0, n-1){
		cin>>a>>b;
		t[i]=60*a+b;
	}
	if(t[0]>s){
		cout<<"0 0\n";
		return 0;
	}
	FOR(i, 1, n-1){
		if(t[i]-t[i-1]-1>=2*s+1){
			odp=t[i-1]+s+1;
			break;
		}
	}
	if(odp==-1){
		odp=t[n-1]+s+1;
	}
	cout<<odp/60<<' '<<odp%60<<'\n';
	return 0;
}