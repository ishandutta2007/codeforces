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

#define MAXN 10000001
int sito[MAXN+1];
bool vis[MAXN+1];
int t[MAXN+1];
VI roz;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, j, wh, licz=0;
	bool alert=false;
	cin>>n;
	wh=n;
	FOR(i, 0, n-1){
		cin>>t[i];
	}
	for(int i=2; i*i<=MAXN; i++){
		if(!sito[i]){
			for(j=i*i; j<=MAXN; j+=i){
				if(!sito[j]){
					sito[j]=i;
				}
			}
		}
	}
	FOR(i, 0, n-1){
		roz.clear();
		j=t[i];
		while(sito[j]){
			roz.PB(sito[j]);
			j/=sito[j];
		}
		roz.PB(j);
		for(auto x: roz){
			if(vis[x]){
				alert=true;
				wh=i;
			}
		}
		if(alert){
			break;
		}
		for(auto x: roz){
			vis[x]=true;
		}
	}
	FOR(i, 0, wh-1){
		cout<<t[i]<<' ';
	}
	if(!alert){
		return 0;
	}
	FOR(i, t[wh]+1, MAXN){
		alert=true;
		roz.clear();
		j=i;
		while(sito[j]){
			roz.PB(sito[j]);
			j/=sito[j];
		}
		roz.PB(j);
		for(auto x: roz){
			if(vis[x]){
				alert=false;
				break;
			}
		}
		if(alert){
			cout<<i<<' ';
			for(auto x: roz){
				vis[x]=true;
			}
			break;
		}
	}
	j=2;
	FOR(i, wh+1, n-1){
		for(; j<=MAXN; j++){
			if(sito[j]==0){
				if(!vis[j]){
					vis[j]=true;
					cout<<j<<' ';
					break;
				}
			}
		}
	}
	cout<<'\n';
	return 0;
}