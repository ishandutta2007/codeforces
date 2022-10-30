#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[200500],vis[200500];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll res=1,f1[200500][2],f2[200500][2];

void dfs(int lst,int x,int len){
	if(a[x]==-1){
		vis[x]=1;
		dfs(lst,x+2,len+1);return;
	}
	int l=lst,r=a[x];
	if(!len)return;
	if(!l&&!r){
		res=res*m%M*ksm(m-1,len-1)%M;return;
	}
	if(!l||!r){
		res=res*ksm(m-1,len)%M;return;
	}
	if(l==r){
		res=res*f2[len][0]%M;return;
	}
	res=res*f1[len][0]%M;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==a[i-2]&&a[i]>0)return puts("0"),0;
	}
	f1[1][1]=1;
	f1[1][0]=m-2;
	f2[1][1]=0;
	f2[1][0]=m-1;
	for(i=2;i<=n+5;i++){
		f1[i][0]=su(f1[i-1][0]*(m-2)%M,f1[i-1][1]*(m-1)%M);
		f1[i][1]=f1[i-1][0];
		f2[i][0]=su(f2[i-1][0]*(m-2)%M,f2[i-1][1]*(m-1)%M);
		f2[i][1]=f2[i-1][0];
	}
	dfs(0,1,0);
	dfs(0,2,0);
	for(i=1;i<=n;i++){
		if(vis[i])continue;
		dfs(a[i],i+2,0);
	}
	printf("%lld",res);
}