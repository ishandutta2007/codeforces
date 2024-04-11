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
	LL cost=0, aktu=1, n, co;
	cin>>n;
	while(n>1){
		co=0;
		if(n%2==1){
			n--;
			co=1;
		}
		n/=2;
		cost+=aktu*n;
		aktu*=2;
		n+=co;
	}
	cout<<cost<<'\n';
	return 0;
}