#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define link(x,y,w)(ne[++js]=la[x],la[x]=js,to[js]=y,le[js]=w)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
using namespace std;
const int mo=998244353,mo2=1e9+7;
const int N=1e6+5,M=5005,G=505;
int n;
int a[N],s[N];
int mx,cmx;
ll ans;
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
void work(int y,ll ss,int x){
	if(x<2)return;
	x=min(x,cmx);
	ss-=(x+y-1)/y*2;
	int g=0,xx=x%y;
	if(xx){
		fo(i,x/y,mx/y)
			g+=s[(i+1)*y-1]-s[i*y+xx-1];
	}
	g=min(g,2);
	if(x<=ss+g){
		ans=max(ans,(ll)x*y);
	}
}
void work2(int y,ll ss,int x,int xxx){
	if(x<2)return;
	x=min(x,mx);
	ss-=(x+y-1)/y;
	int g=0,xx=x%y;
	if(xx){
		fo(i,x/y,mx/y)
			g+=s[(i+1)*y-1]-s[i*y+xx-1];
	}
	g=min(g,1);
	if(xxx<=ss+g){
		ans=max(ans,(ll)xxx*y);
	}
}
int main(){
	R(n);
	fo(i,1,n){
		R(a[i]),++s[a[i]];
		if(a[i]>mx){
			cmx=mx;mx=a[i];
		}else{
			if(a[i]>cmx)cmx=a[i];
		}
	}
	fo(i,1,1e6)s[i]+=s[i-1];
	ans=4;
	fo(y,2,mx){
		ll ss=0;
		fo(i,1,mx/y)
			ss+=(ll)(s[i*y+y-1]-s[i*y-1])*i;
		if(ss>=2){
			int xx=0;
			if(n>1){
				for(int l=2,r=mx,mi;mi=l+r>>1,l<=r;)
					if(mi+((mi+y-1)/y)*2<=ss+2)xx=mi,l=mi+1;else r=mi-1;
				xx=min(xx,cmx);
				fo(o,0,4)work(y,ss,xx-o);
			}
			xx=0;
			for(int l=2,r=mx/2,mi;mi=l+r>>1,l<=r;)
				if(mi+((mi*2+y-1)/y)<=ss+2)xx=mi,l=mi+1;else r=mi-1;
			fo(o,0,3)work2(y,ss,(xx-o)*2,xx-o);
		}else
			break;
	}
	cout<<ans;
}