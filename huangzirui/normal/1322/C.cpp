#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=2000010,mod=1e9+7,f=131,g=18253;
int i,j,k,n,m,T,l,c[maxn],Hash[maxn],D[maxn];
map<int,int>M;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	cin>>T;
	while(T--){
		n=read();l=read();
		D[0]=1;M.clear();
		for(i=1;i<=n;i++)c[i]=read(),Hash[i]=0,D[i]=(1ll*D[i-1]*f*f+1ll*D[i-1]*f+g)%mod;
		for(i=1;i<=l;i++){
			int x=read(),y=read();y+=n;
			Hash[y]+=D[x];
			Hash[y]%=mod;
			//cout<<x<<' '<<y<<' '<<D[x]<<' '<<Hash[y]<<endl;
		}
		//for(i=1;i<=n;i++)cout<<D[i]<<' ';cout<<endl;
		for(i=1;i<=n;i++)if(Hash[i+n])M[Hash[i+n]]+=c[i];
		int ans=M[Hash[1]];
		for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
			ans=gcd(ans,(*it).second);
		for(i=1;i<=n*2;i++)Hash[i]=0,D[i]=0;
		printf("%lld\n",ans);
	}
}