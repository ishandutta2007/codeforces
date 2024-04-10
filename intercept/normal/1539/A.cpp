#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x,t;
void work(){
	scanf("%d%d%d",&n,&x,&t);
	ll y=min(n-1,t/x),ans=1ll*y*(n-1-y)+1ll*y*(y+1)/2;
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}