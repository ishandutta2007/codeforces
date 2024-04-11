#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 2123456789
#define INF INT_MAX/2
#define MOD 1000000007

int n,k;
int meio;
int v[2123];
int memo[2123][2123];

bool goodrange(int a,int b){
	if(a==0)return true;
	if((abs(v[b]-v[a-1])+b-a)/(b-a+1)<=meio)
		return true;
	return false;
}

//onde estou, ultimo que nao mantive
int dp(int i, int u){
	if(i==n)return n-u;
	if(memo[i][u]==-1){
		memo[i][u]=dp(i+1,u);
		if(goodrange(u,i)){
			memo[i][u]=min(memo[i][u],i-u+dp(i+1,i+1));
		}
	}
	//if(meio==1)cout<<i<<" "<<u<<" "<<memo[i][u]<<endl;
	return memo[i][u];

}

void reset(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			memo[i][j]=-1;
		}
	}
}


int bsearch(){
	int com=0,fim=2123456789,best;
	while(com<=fim){
		//cout<<com<<" "<<fim<<endl;
		reset();
		meio=fim-((fim-com)/2);
		if(dp(0,0)<=k){
			best=meio;
			fim=meio-1;
		}
		else com=meio+1;
	}
	return best;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k;
	//cin>>meio;

	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>v[i];

	cout<<bsearch()<<endl;

	//reset();
	//cout<<dp(0,0)<<endl;


	return 0;
}