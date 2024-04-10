#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2005;
int c[maxn][maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
ll C(int n,int m){
	ll ans=1;
	if(m>n/2)m=n-m;
	for(int i=n;i>=n-m+1;i--)ans=1ll*ans*i;
	for(int i=1;i<=m;i++)ans=ans/i;
	return ans;
}
int main(){
	int n,k;
	n=read();k=read();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)c[i][j]=c[j][i]=read();
	ll ans=0;
	for(int i=1;i<=n;i++){
		int d=0;
		ll sum=0;
		for(int j=1;j<=n;j++)if(c[i][j]!=-1)d++,sum+=c[i][j];d--;
		if(d<k)continue;
		ans+=1ll*sum*C(d-1,k-1);
	}
	printf("%lld\n",ans/C(n,k));
	return 0;
}