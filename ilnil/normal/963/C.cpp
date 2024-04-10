#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define ll long long
using namespace std;
const int N=2e5+5,mo=1e7+7;
ll n,h1[mo],h2[mo],an,uk,kk,g;
int la1[N],la2[N],ne1[N],ne2[N],x1,x2,t1,t2;
int w1[mo],w2[mo];
struct no{
	ll w,h,c;
}a[N];
void R(ll &n){
	char c;for(;(c=getchar())<'0'||c>'9';);
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
bool cmp(no x,no y){return x.w<y.w||x.w==y.w&&x.h<y.h;}
int ha1(ll x){
	int y=x%mo;
	for(;h1[y]&&h1[y]!=x;)++y==mo?y=0:0;
	return y;
}
int ha2(ll x){
	int y=x%mo;
	for(;h2[y]&&h2[y]!=x;)++y==mo?y=0:0;
	return y;
}
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
int main(){
//	freopen("a.in","r",stdin);
	R(n);
	fo(i,1,n){
		R(a[i].w),R(a[i].h),R(a[i].c);
		x1=ha1(a[i].w);x2=ha2(a[i].h);
		if(!h1[x1])h1[x1]=a[i].w,w1[x1]=++t1;
		if(!h2[x2])h2[x2]=a[i].h,w2[x2]=++t2;
		x1=w1[x1];x2=w2[x2];
		ne1[i]=la1[x1];ne2[i]=la2[x2];
		la1[x1]=la2[x2]=i;
	}
	if((ll)t1*t2==n){
		kk=a[1].c;
		fo(i,2,n)kk=gcd(a[i].c,kk);
		an=1;uk=kk;
		fo(i,2,1000000){
			if((ll)i*i>kk)break;
			if(kk%i==0){
				for(g=1;kk/=i,kk%i==0;g++);
				an*=(g+1);
			}
		}
		if(kk>1)an*=2;
		fo(i,1,n)a[i].c/=uk;
		fo(i,1,t1){
			kk=0;
			for(int j=la1[i];j;j=ne1[j])kk=gcd(a[j].c,kk);
			for(int j=la1[i];j;j=ne1[j])a[j].c/=kk;
		}
		fo(i,1,t2){
			kk=0;
			for(int j=la2[i];j;j=ne2[j])kk=gcd(a[j].c,kk);
			for(int j=la2[i];j;j=ne2[j])a[j].c/=kk;
		}
		fo(i,1,n)if(a[i].c!=1)an=0;
	}
	printf("%I64d",an);
}