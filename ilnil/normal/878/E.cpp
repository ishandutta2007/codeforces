#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define get(l,r)(-(ll)b[r+1]*_[(r)-(l)+1]+b[l])
using namespace std;
const int N=5e5+5,mo=1e9+7;
int n,q,l,r,bl;
int a[N],b[N],_[N],la[N],ans[N];
struct nod{int l,ne;}t[N];
int f[N],d[N],ds,s[N],ri[N];
ll v[N];
bool is;
void R(int &n){
	char c;int fh=1;for(n=0;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
void P(int n){
	if(!n)putchar('0');
	int j=0;char o[30];
	for(;n;n/=10)o[++j]=n%10+48;
	for(;j;)putchar(o[j--]);putchar('\n');
}
inline int F(int x){return x==f[x]?x:f[x]=F(f[x]);}
int main(){
	R(n);R(q);
	fo(i,1,n)R(a[i]);
	fd(i,1,n)b[i]=((ll)b[i+1]+a[i])*2%mo;
	_[0]=1;
	fo(i,1,n)_[i]=_[i-1]*2%mo,f[i]=i;
	fo(i,1,q){
		R(l);R(r);
		t[i]=(nod){l,la[r]};la[r]=i;
	}
	ds=0;
	fo(i,1,n){
		ll vv=a[i];int le=i;
		for(;ds&&vv>0;){
			int len=le-d[ds];
			vv=len>30||v[ds]+(vv<<len)>mo?vv=mo:v[ds]+(vv<<len);
			f[le]=d[ds];le=d[ds--];
		}
		d[++ds]=le;v[ds]=vv;s[le]=(get(le,i)+s[d[ds-1]])%mo;ri[le]=i;
		for(int j=la[i];j;j=t[j].ne){
			l=t[j].l;
			if(l==i){
				ans[j]=a[l];continue;
			}
			bl=F(l+1);
			ans[j]=(get(l+1,ri[bl])+a[l]+s[le]-s[bl])%mo;
		}
	}
	fo(i,1,q)P((ans[i]+mo)%mo);
}