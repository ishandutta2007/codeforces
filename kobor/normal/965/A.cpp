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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, n, s, p, x=0, d=0;
	cin>>k>>n>>s>>p;
	x=n/s;
	if(n%s)
		x++;
	//cout<<x<<'\n';
	x*=k;
	if(x%p){
		d=1;
	}
	x/=p;
	x+=d;
	cout<<x<<'\n';
	return 0;
}