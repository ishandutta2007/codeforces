#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,t,dp[100500],p,x,y;
ll res;
char sb[100500];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		cin>>sb+1>>x>>y;
		for(i=1;i<=n;i++){
			dp[i]=0;
		}
		for(i=n;i>=1;i--){
			if(i+k>n){
				if(sb[i]=='1'){
					dp[i]=0;
				}
				else{
					dp[i]=x;
				}
				continue;
			
			}
			if(sb[i]=='1'){
				dp[i]=dp[i+k];
			}
			else{
				dp[i]=dp[i+k]+x;
			}
		}
		res=1e11;
		for(i=p;i<=n;i++){
			res=min((ll)(i-p)*y+dp[i],res);
		}
		printf("%lld\n",res);
	}
}