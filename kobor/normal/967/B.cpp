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

LD t[100010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	LD a, b, f, sum=0, wyn=0;
	cin>>n>>a>>b;
	cin>>f;
	sum+=f;
	FOR(i, 0, n-2){
		cin>>t[i];
		sum+=t[i];
	}
	sort(t, t+n-1);
	if(f*a/sum>=b){
		cout<<wyn<<'\n';
		return 0;
	}
	FORD(i, n-2, 0){
		sum-=t[i];
		wyn++;
		if(f*a/sum>=b){
			cout<<wyn<<'\n';
			return 0;
		}
	}
	return 0;
}