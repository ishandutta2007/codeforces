#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
using namespace std;
const int mo=1e5+7,M=4e7;
ll n,k,h[mo],f[55][20],ff[55][mo],sp[55];
int d[mo],dy[mo],nu;
int p[1952000],ps;
int t,w[mo],ss,hx,ws,sf[55];
bool b[M];
int ha(ll x){
	int y=x%mo;
	for(;h[y]&&h[y]!=x;)++y==mo?y=0:0;
	return y;
}
void get(ll x,int w){
	sf[w]=0;
	fo(i,1,ps){
		if((ll)p[i]*p[i]>x)break;
		if(x%p[i]==0){
			f[w][++sf[w]]=p[i];
			while(x/=p[i],x%p[i]==0);
		}
	}
	if(x>1)f[w][++sf[w]]=x;
}
void up(ll *f,int x){
	for(int y;y=x>>1,f[d[x]]<f[d[y]];dy[d[x]]=x,x=y)
		swap(d[x],d[y]);
	dy[d[x]]=x;
}
void dw(ll *f,int x){
	for(int y;y=x<<1,y<=nu&&f[d[y]]<f[d[x]]||y<nu&&f[d[y|1]]<f[d[x]];swap(d[x],d[y]),dy[d[x]]=x,x=y)
		if(y<nu&&f[d[y|1]]<f[d[y]])y++;
	dy[d[x]]=x;
}
void gets(ll *f,ll *p,int s){
	int mp=p[1],mx,x;
	fo(i,0,mp-1)f[i]=1e18,d[i+1]=i,dy[i]=i+1;
	f[0]=0;nu=mp;
	for(;nu;){
		x=d[1];d[1]=d[nu--];dw(f,1);
		fo(i,2,s)
			if(f[x]+p[i]<f[mx=(x+p[i])%mp])
				f[mx]=f[x]+p[i],up(f,dy[mx]);
	}
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!y){x=1;y=0;return;}
	exgcd(b,a%b,x,y);
	ll t=x;x=y;y=t-a/b*y;
}
ll ksm(ll x,ll y,ll mo){
	ll t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a2.out","w",stdout);
	fo(i,2,31622776){
		if(!b[i])p[++ps]=i;
		for(int j=1;j<=ps&&i*p[j]<=31622776;j++){
			b[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(scanf("%d",&t);t--;){
		scanf("%I64d%I64d",&n,&k);
		hx=ha(k);
		if(!h[hx]){
			h[hx]=k;w[hx]=++ws;get(k,ws);
			if(sf[ws]>2)gets(ff[ws],f[ws],sf[ws]);
		}
		hx=w[hx];
		if(!sf[hx])printf("NO");else
		if(sf[hx]==1)printf(n%k?"NO":"YES");else
		if(sf[hx]==2){
			ll a=f[hx][1],b=f[hx][2];
			if(n>a*b-a-b){printf("YES\n");continue;}
			printf((ksm(b%a,a-2,a)*(n%a))%a*b<=n?"YES":"NO");
		}else printf(ff[hx][n%f[hx][1]]<=n?"YES":"NO");
		printf("\n");
	}
}