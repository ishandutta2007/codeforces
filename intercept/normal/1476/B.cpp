#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k;
void work(){
	scanf("%d%d",&n,&k);
	ll sum=0,p,ans=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&p);
		if(i>1){
			if(100ll*p>k*sum){
				ll x=(100ll*p-k*sum-1)/k+1;
				ans+=x;
				sum+=x;
			}
		}
		sum+=p;
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}