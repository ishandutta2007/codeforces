#include<bits/stdc++.h>
using namespace std;
#define N 680
#define int long long
int p[N],is[N],d,i,tot,j,cnt,ge,f[N],MAX=1e18,res,T,u[N],X,ans,cc,p1,p2,P;
signed main(){
	for(i=2;i<N;++i){
		if(!is[i])p[++cnt]=i;
		for(j=1;j<=cnt&&(d=i*p[j])<N;++j){
			is[d]=1;if(i%p[j]==0)break;
		}
	}
	f[tot=1]=1;
	for(i=1;i<=cnt;++i){
		if(MAX/p[i]>=f[tot])f[tot]*=p[i];
		else f[++tot]=p[i];
	}
	cin>>T;
	while(T--){
		cc=0;ans=1;
		for(i=1;i<=17;++i){
			cout<<"? "<<f[i]<<"\n";
			cin>>ge;
			for(j=1;j<=cnt;++j)if(ge%p[j]==0)u[++cc]=p[j];
		}
		if(cc==0){cout<<"! "<<8<<"\n";continue;}
		X=1e9;
		for(i=1;i<=cc;i+=2){
			p1=u[i],p2=u[i+1];
			if(i==cc)p2=u[i+1]=1000000000;
			while(p1*u[i]<=X)p1*=u[i];while(p2*u[i+1]<=X)p2*=u[i+1];
			cout<<"? "<<p1*p2<<"\n";
			cin>>ge;res=1;
			while(ge%u[i]==0)ge/=u[i],++res;
			ans*=res;res=1;
			while(ge%u[i+1]==0)ge/=u[i+1],++res;
			ans*=res;
		}
		if(ans<=4)cout<<"! "<<8<<"\n";
		else cout<<"! "<<ans*2<<"\n";
	}
}