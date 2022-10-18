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

bool t[101][101];
int zlicz1[101][101];
int zlicz2[101][101];
int loc[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, maks=-1, xo=0, yo=0;
	char x;
	cin>>n>>k;
	FOR(i, 1, n){
		FOR(j, 1, n){
			cin>>x;
			if(x=='.')
				t[i][j]=true;
		}
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(t[i][j])
				zlicz1[i][j]=zlicz1[i][j-1]+1;
		}
	}
	FOR(j, 1, n){
		FOR(i, 1, n){
			if(t[i][j])
				zlicz2[i][j]=zlicz2[i-1][j]+1;
		}
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(zlicz1[i][j]>=k){
				FORD(jo, j, j-k+1){
					loc[i][jo]++;
				}
			}
			if(zlicz2[i][j]>=k){
				FORD(jo, i, i-k+1){
					loc[jo][j]++;
				}
			}
		}
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(loc[i][j]>maks){
				maks=loc[i][j];
				xo=j;
				yo=i;
			}
		}
	}
	cout<<yo<<' '<<xo<<'\n';
	return 0;
}