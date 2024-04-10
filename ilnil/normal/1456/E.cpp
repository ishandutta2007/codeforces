#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define cls(x) memset(x,0,sizeof x)
#define cpy(x,y) memcpy(x,y,sizeof y)
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
#define ul unsigned ll
#define ui unsigned int
#define db double
#define ldb long double
#define bit(x,y)((x)>>(y)&1)
using namespace std;
const int N=55;
const ll inf=4e18;
int n,k;
int can[N][N][2];
ll c[N],lim[N][N],f[N][N][2][N][2],g[N][2],dp[N][2];
ll get(int w,int l,int r,int lv,int rv,int cx=0){
	if(l==0||r==n+1)return 0;
	return c[w]*(bit(lim[l][lv]^lim[r][rv],w)^cx);
}
#define cmin(x,y)(x=min(x,y))
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&k);
	fo(i,1,n){
		scanf("%lld%lld",&lim[i][0],&lim[i][1]);
		int v=-1;
		fd(j,0,k-1)if(bit(lim[i][0],j)!=bit(lim[i][1],j)){v=j;break;}
		++v;
		fo(j,0,v-2){
			if(!bit(lim[i][0],j))can[j][i][0]=1;
			if(bit(lim[i][1],j))can[j][i][1]=1;
		}
	}
	fo(i,0,k-1)scanf("%lld",&c[i]);
	fo(l,0,n+1)fo(lv,0,1)fo(r,l+1,n+1)fo(rv,0,1){
		if(l+1==r)
			f[k-1][l][lv][r][rv]=get(k-1,l,r,lv,rv);
		else
			f[k-1][l][lv][r][rv]=inf;
	}
	fd(w,0,k-2){
		fo(l,0,n)fo(lv,0,1){
			fo(r,l,n+1)fo(rv,0,1)f[w][l][lv][r][rv]=g[r][rv]=inf;
			g[l][lv]=0;
			fo(j,l,n)fo(jv,0,1)if(g[j][jv]<inf){
				ll v=g[j][jv];
				fo(r,j+1,n+1)fo(rv,0,1)if(f[w+1][j][jv][r][rv]<inf){
					ll v2=f[w+1][j][jv][r][rv];
					if(can[w][r][rv])
						cmin(g[r][rv],v+v2+get(w,j,r,jv,rv,1^(l!=j)));
					cmin(f[w][l][lv][r][rv],v+v2+get(w,j,r,jv,rv,l!=j));
				}
			}
		}
	}
//	fo(i,0,n)printf("%d ",f[0][i][0][i+1][0]);
	fo(i,0,n+1)fo(iv,0,1)dp[i][iv]=inf;
	dp[0][0]=0;
	fo(j,0,n)fo(jv,0,1)if(dp[j][jv]<inf)
		fo(i,j+1,n+1)fo(iv,0,1)cmin(dp[i][iv],dp[j][jv]+f[0][j][jv][i][iv]);
	printf("%lld\n",dp[n+1][0]);
}