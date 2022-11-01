#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
using namespace std;
const int N=2e5+5,mo=1e9+7;
int n,x,y,js,la[N],ne[N*2],to[N*2],v[N],p[N];
ll ans,an[N][4],g[N][4],aa;
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
void dfs(int x){
	int y;
	ff(i,x)if((y=to[i])!=p[x]){
		p[y]=x;
		dfs(y);
		an[x][1]=(g[y][0]*(mo-v[x])+an[y][0]+an[x][1])%mo;
		g[x][1]+=g[y][0];
		an[x][0]=(g[y][1]*v[x]+an[y][1]+an[x][0])%mo;
		g[x][0]+=g[y][1];
		an[x][3]=(an[x][3]+g[y][2]*(mo-v[x])+an[y][2])%mo;
		g[x][3]+=g[y][2];
		an[x][2]=(an[x][2]+(ll)v[x]*g[y][3]+an[y][3])%mo;
		g[x][2]+=g[y][3];
	}
	ans=(ans+an[x][0]+an[x][1]+an[x][2])%mo;
	aa=0;
	ff(i,x)if((y=to[i])!=p[x]){
		aa=(aa+(an[x][0]-g[y][1]*v[x]%mo-an[y][1]+mo*2)%mo*g[y][3]+an[y][3]*(g[x][0]-g[y][1])+
			(an[x][1]-g[y][0]*(mo-v[x])%mo-an[y][0]+mo*2)%mo*g[y][2]+an[y][2]*(g[x][1]-g[y][0]))%mo;
		aa=(aa+(an[x][2]-g[y][3]*v[x]%mo-an[y][3]+mo*2)%mo*g[y][1]+an[y][1]*(g[x][2]-g[y][3])+
			(an[x][3]-g[y][2]*(mo-v[x])%mo-an[y][2]+mo*2)%mo*g[y][0]+an[y][0]*(g[x][3]-g[y][2]))%mo;
	}
	ans=(ans+aa*(mo+1>>1)+v[x])%mo;
	an[x][0]=(an[x][0]+v[x])%mo;g[x][0]++;
	an[x][2]=(an[x][2]+v[x])%mo;g[x][2]++;
	an[x][3]=(an[x][3]+mo-v[x])%mo;g[x][3]++;
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);
	fo(i,1,n)R(v[i]),v[i]=(v[i]+mo)%mo;
	fo(i,2,n)R(x),R(y),link(x,y),link(y,x);
	dfs(1);
	printf("%I64d",ans);
}