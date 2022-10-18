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

int t[1000000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, suma=0, s=0;
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
		suma+=t[i];
	}
	FOR(i, 1, n){
		s+=t[i];
		if(2*s>=suma){
			cout<<i<<'\n';
			return 0;
		}
	}
	return 0;
}