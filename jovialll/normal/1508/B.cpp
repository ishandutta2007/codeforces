#include<bits/stdc++.h>
using namespace std;
char buf[100000],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
int T,n,i,j,las,f[100005];long long k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(n<=60&&(1ll<<n-1)<k){cout<<"-1\n";continue;}
		--k;
		for(i=1;i<n;++i){
			if((k>>min(60,n-i-1))&1)f[i]=1;
			else f[i]=0;
		}f[n]=0;
		las=1;
		for(i=1;i<=n;++i){
			if(f[i]==1){
				for(j=i;j<=n;++j)if(!f[j])break;
				for(;j>=i;--j)cout<<j<<" ";
				while(f[i])++i;
			}
			else cout<<i<<" ";
		}
		cout<<"\n";
	}
}