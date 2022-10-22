#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n;
int b[M];
map<ll,int>ma;
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	ma.clear();
	ma[0]=1;
	int ans=1;ll sum=0;
	for(int i=1;i<=n;++i){
		int t=ans;
		ans=(1ll*ans+ans-ma[sum]+mod)%mod;
		ma[sum]=t;
		sum-=b[i];
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}