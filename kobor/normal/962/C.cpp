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
	int n, wyn=INF, k;
	string a, b;
	cin>>n;
	a=to_string(n);
	for(int i=1; i*i<=n; i++){
		b=to_string(i*i);
		k=0;
		for(int j=0; j<SIZE(a); j++){
			if(k==SIZE(b)){
				break;
			}
			if(a[j]==b[k]){
				k++;
			}
		}
		if(k==SIZE(b)){
			wyn=min(wyn, SIZE(a)-SIZE(b));
		}
	}
	if(wyn==INF){
		wyn=-1;
	}
	cout<<wyn<<'\n';
	return 0;
}