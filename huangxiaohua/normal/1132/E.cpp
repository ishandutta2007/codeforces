#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t;
ll res,a[10],m,sb;

void dfs(ll x,ll y){
	if(!x){res=max(res,y);return;}
	ll sb=min((m-y)/x,a[x]);
	for(ll i=0;i<=7;i++){
		if(i>sb){return;}
		dfs(x-1,y+x*(sb-i));
	}
}

int main(){
	scanf("%lld",&m);
	for(i=1;i<=8;i++){
		scanf("%lld",&a[i]);
	}
	sb=min(m/8,a[i]);
	dfs(8,0);
	printf("%lld",res);
}