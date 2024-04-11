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
	int n, a, b, wyn=0, dec=0;
	string s;
	cin>>n>>a>>b>>s;
	FOR(i, 0, SIZE(s)-1){
		if(a<b){
			swap(a, b);
		}
		if(a==0){
			break;
		}
		if(s[i]=='.'){
			a--;
			wyn++;
			i++;
			if(i==SIZE(s)){
				break;
			}
			if(s[i]=='.'&&b>0){
				b--;
				wyn++;
			}
		}
	}
	cout<<wyn<<'\n';
	return 0;
}