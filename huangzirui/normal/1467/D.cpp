#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=5010,mod=1e9+7;
int i,j,k,n,m,T;
ll num[maxn][maxn],w[maxn],s[maxn],ans,a[maxn],tmp[maxn],Pow[maxn];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)num[0][i]=s[i]=w[i]=1;
	for(int T=1;T<=m;T++){
		for(i=1;i<=n;i++)tmp[i]=(num[T-1][i-1]+num[T-1][i+1])%mod;
		for(i=1;i<=n;i++)s[i]=num[T][i]=tmp[i];
	}
	for(int T=1;T<=m;T++){
		for(i=1;i<=n;i++)tmp[i]=(w[i-1]+w[i+1])%mod;
		for(i=1;i<=n;i++)w[i]=tmp[i],s[i]+=w[i]*num[m-T][i],s[i]%=mod;
	}
	for(i=1;i<=n;i++)a[i]=read(),ans+=1ll*a[i]*s[i]%mod/*,cout<<num[m][i]<<' '<<s[i]<<endl*/;
	for(i=1;i<=k;i++){
		int x=read(),y=read();
		ans-=1ll*a[x]*s[x]%mod;
		a[x]=y;
		ans+=1ll*a[x]*s[x]%mod;
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans);
	}
}