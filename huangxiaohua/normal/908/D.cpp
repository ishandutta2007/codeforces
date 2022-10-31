#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int i,j,k,n,m,vis[1050][1050];
ll a,b,inv,f[1050][1050],res,sb;

void dfs(int x,int y){
	if(x<0||y<0){return;}
	vis[x][y]=1;
	if((x-1+y)<n){
		if(!vis[x-1][y]){dfs(x-1,y);}
		if(x){f[x][y]=(f[x][y]+f[x-1][y]*a)%M;}
	}
	if(!vis[x][y-x]){dfs(x,y-x);}
	if(y>=x){f[x][y]=(f[x][y]+f[x][y-x]*b)%M;}
}

int main(){
	vis[1][0]=f[1][0]=1;
	scanf("%d%lld%lld",&n,&a,&b);
	sb=a+b;
	a=a*ksm(sb,M-2)%M;
	b=b*ksm(sb,M-2)%M;
	inv=a*ksm((1+M-a)%M,M-2)%M*ksm((1+M-a)%M,M-2)%M*b%M;
	for(i=0;i<=n;i++){
		for(j=0;j<n;j++){
			if(i+j>=n){
				dfs(i,j);
				res=(res+(i+j+inv)*f[i][j])%M;
			}
		}
	}
	printf("%lld",res);
}