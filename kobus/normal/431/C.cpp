#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007
//#define int long long

int memo[101][2];
int n,k,d;

int dp(int resta,bool usou){
	if(resta<0)return 0;
	if(resta==0)return usou;
	if(memo[resta][usou]==-1){
		int resp=0;
		for(int i=1;i<=k;i++){
			resp+=dp(resta-i,(usou||(i>=d)));
			resp%=MOD;
		}
		memo[resta][usou]=resp%MOD;
	}
	return memo[resta][usou];

}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k>>d;
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++){
			memo[i][j]=-1;
		}
	}
	cout<<dp(n,0)<<endl;



	return 0;
}