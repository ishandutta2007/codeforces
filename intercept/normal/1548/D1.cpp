#include<bits/stdc++.h>
using namespace std;
int n;
int b[4];
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		b[(x&2)|(y>>1&1)]++;
	}
	long long ans=0;
	for(int i=0;i<4;++i){
		ans=ans+1ll*b[i]*(b[i]-1)/2*(n-b[i])+1ll*b[i]*(b[i]-1)*(b[i]-2)/6;
	}
	printf("%lld\n",ans);
	return 0;
}