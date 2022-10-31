#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,t;
ll sb[200500],res,mx;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=0;mx=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&sb[i]);
			if(i>=2){
				res+=abs(sb[i]-sb[i-1]);
			}
		}
		for(i=1;i<=n;i++){
			if(i==1){
				mx=max(mx,abs(sb[i]-sb[i+1]));
			}
			if(i>=2&&i<n){
				mx=max(mx,abs(sb[i]-sb[i-1])+abs(sb[i]-sb[i+1])-abs(sb[i+1]-sb[i-1]));
			}
			if(i==n){
				mx=max(mx,abs(sb[i]-sb[i-1]));
			}
		}
		printf("%lld\n",res-mx);
	}
}