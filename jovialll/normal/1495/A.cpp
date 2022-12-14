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
int T,n,i,j,k,a[N],x[N],y[N],f1[N],f2[N],c1,c2;db ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n;c1=c2=ans=0;
		for(i=1;i<=n+n;++i){
			cin>>x[i]>>y[i];
			if(x[i]<0)x[i]=-x[i];
			if(y[i]<0)y[i]=-y[i];
			if(x[i]==0)f1[++c1]=y[i];
			else f2[++c2]=x[i];
		}
		sort(f1+1,f1+c1+1);
		sort(f2+1,f2+c2+1);
		for(i=1;i<=n;++i)ans+=sqrt(1ll*f1[i]*f1[i]+1ll*f2[i]*f2[i]);
		printf("%.10lf\n",ans);
	}
}