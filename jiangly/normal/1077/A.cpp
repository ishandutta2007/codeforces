#include<bits/stdc++.h>
typedef long long ll;
int t,a,b,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&k);
		printf("%I64d\n",1ll*a*((k+1)/2)-1ll*b*(k/2));
	}
	return 0;
}