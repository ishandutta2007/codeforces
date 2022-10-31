#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,vis[50050],res;
ll x[50050],y[50050],z[50050],mn;
ll get(int a,int b){
	return llabs(x[a]-x[b])+llabs(y[a]-y[b])+llabs(z[a]-z[b]);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	}
	for(i=1;i<=n;i++){
		if(vis[i]){continue;}
		vis[i]=1;
		res=0;mn=1e15;
		for(j=1;j<=n;j++){
			if(vis[j]){continue;}
			if(mn>get(i,j)){
				mn=get(i,j);res=j;
			}
		}
		vis[res]=1;
		printf("%d %d\n",i,res);
	}
}