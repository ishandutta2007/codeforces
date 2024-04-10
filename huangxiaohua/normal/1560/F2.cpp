#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ii,j,k,n,m,t,i;
bool a[15];
ll res;

int chk(int x){
	int k=0;
	while(x){a[x%10]=1;x/=10;}
	for(int i=0;i<=9;i++){k+=a[i];a[i]=0;}
	return k;
}

set<ll> v[15];

void dfs(int dep,int x,ll y){
	v[dep].insert(y);
	if(dep>=10){return;}
	dfs(dep+1,x,y*10+x);
}

void dfs2(int dep,ll y,ll pw){
	if(dep>9){return;}
	for(auto i:v[dep]){
		ll k=i+y*pw;
		if(chk(k)<=j&&k>=ii){res=min(res,k);}
	}
	dfs2(dep+1,y/10,pw*10);
}

int main(){
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			dfs(1,j,i);
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&ii,&j);
		res=1e18;
		dfs2(1,ii/10,10);
		printf("%lld\n",res);
	}
}