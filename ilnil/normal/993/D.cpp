#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[55],b[55],ma;
ll aa[55],an,su,f[55][55][55];
struct no{
	ll a,c;
}c[55];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
bool cmp(no x,no y){return x.a>y.a;}
bool pd(ll x){
	ll ans=0;
	fo(i,1,n)c[i].c=x*b[i]-aa[i],(c[i].c<=0?ans+=c[i].c:0),c[i].a=aa[i];
	sort(c+1,c+n+1,cmp);
	fo(i,0,n)fo(j,0,n+1)fo(k,0,n)f[i][j][k]=ans;
	f[0][0][0]=0;
	fo(i,1,n){
		if(c[i].a!=c[i-1].a)
			fo(j,0,n)fo(k,1,n-j)f[i-1][j+k][0]=max(f[i-1][j+k][0],f[i-1][j][k]),f[i-1][j][k]=ans;
		fo(j,0,n)fo(k,0,n){
			if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+c[i].c);
			f[i][j][k]=max(f[i][j][k],f[i-1][j+1][k]);
		}
	}
	fo(i,0,n)fo(j,0,n-j)if(f[n][i][j]>=0)return 1;
	return 0;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	R(n);
	fo(i,1,n)R(a[i]),aa[i]=(ll)a[i]*1000,su+=aa[i];
	fo(i,1,n)R(b[i]);
	for(ll l=0,r=su,m;m=l+r>>1,l<=r;)
		if(pd(m))an=m,r=m-1;else l=m+1;
	printf("%I64d ",an);
}