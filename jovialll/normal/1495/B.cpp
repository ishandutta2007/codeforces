#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define N 1000005
#define ls (k<<1)
#define rs (k<<1|1)
#define yes puts("Yes\n");
#define no puts("No\n");
#define mod 998244353

//#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
//char buf[1<<21],*p1,*p2,ch;
//int ret;
//inline int re() {
//	ret=0;
//	ch=getc();
//	while(!isdigit(ch)){
//		ch=getc();
//	}
//	while(isdigit(ch)){
//		ret=(ret<<1)+(ret<<3)+(ch^48);
//		ch=getc();
//	}
//	return ret;
//}
inline int re(){int x;cin>>x;return x;} 
inline ll ksm(ll x,ll y){ll r=1;for(;y;y>>=1,x=x*x%mod)if(y&1)r=r*x%mod;return r;}
int T,n,i,j,k,a[N],ans,L[N],l1,l2,R[N],l[N],r[N],s[N],p[N];
int main(){
	n=re();
	for(i=1;i<=n;++i){
		a[i]=re();
	}
	L[1]=1;
	for(i=2;i<=n;++i){
		if(a[i]>a[i-1])L[i]=L[i-1];
		else L[i]=i;
	}
	R[n]=n;
	for(i=n-1;i;--i){
		if(a[i]>a[i+1])R[i]=R[i+1];
		else R[i]=i;
	}
	l[1]=1;
	for(i=2;i<=n;++i){
		if(a[i]<a[i-1])l[i]=l[i-1];
		else l[i]=i;
	}
	r[n]=n;
	for(i=n-1;i;--i){
		if(a[i]<a[i+1])r[i]=r[i+1];
		else r[i]=i;
	}
	for(i=2;i<=n;++i){
		p[i]=max(p[i-1],max(i-l[i],i-L[i]));
	}
	for(i=n-1;i;--i){
		s[i]=max(s[i+1],max(r[i]-i,R[i]-i));
	}
	for(i=1;i<=n;++i){
		if(L[i]<i&&R[i]>i){
			l1=i-L[i];l2=R[i]-i;
			if(max(l1,l2)>max(p[L[i]],s[R[i]])){
				if(l1==l2&&(l1&1)==0)++ans;
			}
		}
	}
	cout<<ans;
}