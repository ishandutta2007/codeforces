#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,l,n,m,t,it,nu,a[66]={-114514,1};
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
ll g[66][66],h[66][66][66],res;

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(ll x,ll y){
	if(x<0||y<0||x<y)return 0;
	ll res=1;for(int i=1;i<=y;i++)res=res*(x+1-i)%M*ksm(i,M-2)%M;
	return res;
}

void dfs(int d,ll f){
	g[d][a[d]]=su(g[d][a[d]],f);
	if(d==m)return;
	for(int i=1;i<=nu;i++){
		a[d+1]=a[d]+i;
		for(int j=d;j>=0;j--)if(a[j]+nu<a[d+1]){
			dfs(d+1,f*(d+1-j)%M);break;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>nu;
	dfs(1,1);
	h[0][0][0]=1;
	for(t=0;t<=m;t++)for(i=0;i<=m;i++)for(j=0;j<=50;j++){
		for(k=1;k<=m;k++)for(l=1;l<=50;l++){
			h[i+k][j+l][t+1]=su(h[i+k][j+l][t+1],h[i][j][t]*g[k][l]%M);
		}
	}
	for(i=1;i<=50;i++)for(j=1;j<=m;j++){
		ll x=c(n-(i-j)-(j-1)*(nu),j),y=h[m][i][j];
		res=su(res,x*y%M);
	}
	cout<<res;
}