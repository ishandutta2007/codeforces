#include<cstring> 
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define pu(x)putchar(x)
#define min(a,b)(a<b?a:b)
using namespace std;
const int N=2e5+5;
int n,m,ans,q,f[N],rk[N];
struct no{
	int x,y;
}a[N];
bool bz;
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void P(int n){
	if(!n){pu('0');return;}
	char c[20];int j=0;
	for(;n;n/=10)c[++j]=n%10+48;
	while(j)pu(c[j--]);
}
bool cmp(no x,no y){return x.y<y.y||x.y==y.y&&x.x<y.x;}
int ff(int x){return f[x]==x?x:f[x]=ff(f[x]);}
void mer(int x,int y){
	int fx=ff(x),fy=ff(y);
	if(fx==fy)return;
	if(rk[fx]<rk[fy])swap(fx,fy);
	f[fy]=fx;rk[fx]+=rk[fx]==rk[fy];
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	R(n);R(m);R(q);
	fo(i,1,q)R(a[i].x),R(a[i].y);
	sort(a+1,a+q+1,cmp);
	fo(i,1,n)f[i]=i,rk[i]=1;
	fo(i,1,q)
		if(a[i].y==a[i-1].y){
			mer(a[i-1].x,a[i].x);
		}else ans--;
	fo(i,1,n)if(ff(i)==i)ans++;
	printf("%d",ans+m-1);
}