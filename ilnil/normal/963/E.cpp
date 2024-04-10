#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
#define ll long long
using namespace std;
const int mo=1e9+7;
ll r,p[4],pp,x,y,an,ys;
int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}},w[102][102],ws;
int po[10005][2],xx,yy;
int f[7850][7850];
ll ksm(ll x,int y){
	ll t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%I64d",&r);
	fo(i,0,3)scanf("%I64d",&p[i]),pp+=p[i];
	pp=ksm(pp,mo-2);
	fo(i,0,3)p[i]=p[i]*pp%mo;
	fo(i,-r,r)fo(j,-r,r)if(i*i+j*j<=r*r)w[i+51][j+51]=++ws,po[ws][0]=i+51,po[ws][1]=j+51;
	fo(i,1,ws){
		x=po[i][0];y=po[i][1];
		f[i][0]=1;f[i][i]=-1;
		fo(j,0,3){
			xx=x+fx[j][0];yy=y+fx[j][1];
			if(w[xx][yy])f[i][w[xx][yy]]=p[j];
		}
	}
	fo(i,1,ws){
		x=ksm(f[i][i],mo-2);
		fo(j,i+1,min(ws,i+2*r)){
			ys=f[j][i]*x%mo;
			if(ys){
				f[j][0]=(f[j][0]-f[i][0]*ys)%mo;
				fo(k,i,min(ws,i+2*r))f[j][k]=(f[j][k]-f[i][k]*ys)%mo;
			}
		}
	}
	fd(i,w[51][51],ws){
		an=-f[i][0]*ksm(f[i][i],mo-2)%mo;
		fd(j,max(i-r*2,w[51][51]),i-1)
			f[j][0]=(f[j][0]+f[j][i]*an)%mo;
	}
	printf("%I64d",(an+mo)%mo);
}