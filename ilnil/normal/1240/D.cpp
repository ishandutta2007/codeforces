#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define link(x,y,w)(ne[++js]=la[x],la[x]=js,to[js]=y,le[js]=w)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
using namespace std;
const int mo=998244353,mo2=1e9+7;
const int N=3e5+5,M=5005,G=505;
int q,n;
int a;
int d[N],ds,ts,cnt[N],fa[N];
ll has,has2;
ll ans;
map<int,int>ne[N];
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
int main(){
	R(q);
	for(;q--;){
		R(n);
		fo(i,1,ts)ne[i].clear(),cnt[i]=0;
		ans=0;
		ts=1;ds=0;
		int j=1;
		cnt[1]=1;
		fo(i,1,n){
			R(a);
			if(!ds||d[ds]!=a){
				if(!ne[j][a])
					ne[j][a]=++ts;
				int las=j;
				j=ne[j][a];
				fa[j]=las;
				d[++ds]=a;
			}else{
				--ds;
				j=fa[j];
			}
			ans+=cnt[j];
			++cnt[j];
		}
		P(ans);
	}
}