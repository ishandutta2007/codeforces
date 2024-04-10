#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define link(x,y,w)(ne[++js]=la[x],la[x]=js,to[js]=y,le[js]=w)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
using namespace std;
const int mo=998244353,mo2=1e9+7;
const int N=5e5+5,M=5005,G=505;
int q,n;
int x,y,w,k;
int la[N],ne[N*2],to[N*2],le[N*2],js;
int fa[N],ds;
ll ans,f[N][2],d[N];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void P(ll n){
	if(!n)putchar('0');
	int j=0;char o[30];
	for(;n;n/=10)o[++j]=n%10+48;
	for(;j;)putchar(o[j--]);putchar('\n');
}
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x){
	ff(i,x)if(to[i]!=fa[x]){
		fa[to[i]]=x;
		dfs(to[i]);
	}
	ll sum=0;
	ds=0;
	ff(i,x)if(to[i]!=fa[x]){
		int y=to[i];
		sum+=f[y][0];
		d[++ds]=f[y][1]-f[y][0]+le[i];
	}
	sort(d+1,d+ds+1,cmp);
	ll sum2=sum;
	fo(i,1,min(k-1,ds))
		if(d[i]>=0)sum2+=d[i];
	f[x][1]=sum2;
	sum2=sum;
	fo(i,1,min(k,ds))
		if(d[i]>=0)sum2+=d[i];
	f[x][0]=sum2;
}
int main(){
	R(q);
	for(;q--;){
		R(n);R(k);
		fo(i,1,n)la[i]=0;
		js=0;
		fo(i,2,n){
			R(x),R(y),R(w);
			link(x,y,w);
			link(y,x,w);
		}
		dfs(1);
		P(f[1][0]);
	}
}