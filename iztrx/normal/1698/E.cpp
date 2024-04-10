#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define mod 998244353
int T,n,i,j,qwq,s,c[N],fl,p[N],a[N],b[N];
ll ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)cin>>b[i],p[a[i]]=b[i];
		fl=0;
		for(i=1;i<=n;++i){
			if(p[i]!=-1&&p[i]<i-s)fl=1;
			if(p[i]!=-1)c[p[i]]=1;
		}ans=1;
		j=1;qwq=0;
		for(i=1;i<=n;++i){
			while(j<=i+s&&j<=n){if(p[j]==-1)++qwq;++j;}
			if(!c[i]&&qwq==0)fl=1;
			else if(!c[i])ans=ans*qwq%mod,--qwq;
		}
		for(i=1;i<=n;++i)c[i]=0;
		if(fl==1)cout<<"0\n";
		else cout<<ans<<"\n";
	}
}