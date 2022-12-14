//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 300025
long long g[N][61],ans,f[N],su[N],s[N],s0[N],s1[N],a,n,m,l,r,t,ll,ss;

int main()
{
	n=read();
	for(int j=1;j<=n;++j)
	{
		a=read();
		for(int i=59;i>=0;--i){
			if(1ll<<i <= a){
				a-=1ll<<i;
				++f[j];
			}
		}
	}
	for(int i=1;i<=n;++i)su[i]=su[i-1]+f[i];
	s0[0]=1;
	for(int i=1;i<=n;++i)s[i]=s[i-1]^(f[i]&1);
	for(int i=1;i<=n;++i)s1[i]=s1[i-1]+s[i],s0[i]=s0[i-1]+(s[i]^1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<f[i];++j)g[i][j]=i;
		for(int j=f[i];j<=60;++j)g[i][j]=g[i-1][j];
	}
	for(int i=1;i<=n;++i){
		t=i-1;
		for(int j=0;j<=60;++j){
			ll=l=g[i][j];if(l>t)continue;
			r=t;
			if(su[i]-su[l]<j*2){
				t=l-1;
				continue;
			}
//			cerr<<i<<' '<<l<<' '<<r<<' '<<j<<endl;
			while(l<=r){
				m=(l+r)>>1;
				if(su[i]-su[m]<j*2)r=m-1;
				else ss=m,l=m+1;
			}
			
			t=ll-1;
			
			if(t<0){
//				cerr<<ss<<' '<<t<<' '<<s[i]<<endl;
				if(s[i])ans+=s1[ss];
				else ans+=s0[ss];
			} else {
			if(!s[i])ans+=s0[ss]-s0[t];
			else ans+=s1[ss]-s1[t]; }
		}
	}
	cout<<ans;
}