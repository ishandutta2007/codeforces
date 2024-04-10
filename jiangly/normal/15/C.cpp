#include<bits/stdc++.h>
typedef long long ll;
int n;
ll ans;
ll sum(ll x,ll m){
	return !m?0:(x&1)?(x^sum(x+1,m-1)):(m&1)?((x+m-1)^sum(x,m-1)):(m&2)?1:0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		ll x,m;
		scanf("%I64d%I64d",&x,&m);
		ans^=sum(x,m);
	}
	if(ans)
		puts("tolik");
	else
		puts("bolik");
	return 0;
}