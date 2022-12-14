#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1050000
int i,j,k,r,n,m,mx,a[22][100005],g[1025];
ll c[N],b[N],e[N],ans,x,y;
int bc(int x){if(!x)return 0;return bc(x/2)+(x&1);}
void FWT(ll *f,int typ){
	for(i=1;i<mx;i<<=1)for(r=i+i,j=0;j<mx;j+=r)for(k=0;k<i;++k){
		x=f[j+k];y=f[i+j+k];f[j+k]=x+y,f[i+j+k]=x-y;
		if(typ==-1)f[j+k]=f[j+k]/2ll,f[i+j+k]=f[i+j+k]/2ll;
	}
}char ch;
signed main(){ios::sync_with_stdio(false);
	cin>>n>>m;mx=(1<<n);for(i=1;i<=n;++i)for(j=1;j<=m;++j)cin>>ch,a[i][j]=ch-'0';
	for(i=1;i<=m;++c[r],++i)for(r=0,j=n;j;--j)r=(r<<1)+a[j][i];
	for(i=1;i<1024;++i)g[i]=bc(i);for(i=1;i<mx;++i)b[i]=g[i%1024]+g[i/1024];
	for(i=0;i<mx;++i)b[i]=min(b[i],n-b[i]);
	FWT(b,1);FWT(c,1);
	for(i=0;i<mx;++i)e[i]=b[i]*c[i];
	FWT(e,-1);
	ans=1e8;for(i=0;i<mx;++i)ans=min(ans,e[i]);
	cout<<ans;
}