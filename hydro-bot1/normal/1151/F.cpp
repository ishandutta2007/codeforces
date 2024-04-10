// Hydro submission #62c7d7cb8672efa577c0e720@1657264076485
#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=1e9+7;
struct mat{int cnt[N][N];};
int sum,p[N],s[2],siz;
mat operator*(mat a,mat b){
	mat ans;
	memset(ans.cnt,0,sizeof(ans.cnt));
	for(int i=0;i<=siz;i++)
		for(int j=0;j<=siz;j++)
			for(int k=0;k<=siz;k++)
				ans.cnt[i][j]=(ans.cnt[i][j]+1ll*a.cnt[i][k]*b.cnt[k][j]%mod)%mod;
	return ans;
}
int kuai(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
mat kuai(mat a,int b){
	mat ans;
	memset(ans.cnt,0,sizeof(ans.cnt));
	for(int i=0;i<=siz;i++)ans.cnt[i][i]=1;
	for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
	return ans;
}
int n,m;
mat a,c;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>p[i],s[p[i]]++;
	siz=min(s[0],s[1]);
	for(int i=1;i<=s[0];i++)sum+=p[i];
	a.cnt[0][sum]=1;
	for(int i=0;i<=siz;i++)c.cnt[i][i]=(1ll*s[0]*(s[0]-1)/2%mod+s[1]*(s[1]-1)/2%mod)%mod;
	for(int i=0;i<=siz;i++){
		if(i>0)c.cnt[i][i-1]=1ll*i*i%mod;
		(c.cnt[i][i]+=(1ll*i*(s[1]-i)%mod+1ll*(s[0]-i)*i%mod)%mod)%=mod;
		if(i<siz)c.cnt[i][i+1]=1ll*(s[0]-i)*(s[1]-i)%mod;
	}
	int Inv=kuai(1ll*n*(n-1)/2%mod,mod-2);
	for(int i=0;i<=siz;i++){
		if(i>0)c.cnt[i][i-1]=1ll*c.cnt[i][i-1]*Inv%mod;
		c.cnt[i][i]=1ll*c.cnt[i][i]*Inv%mod;
		if(i<siz)c.cnt[i][i+1]=1ll*c.cnt[i][i+1]*Inv%mod;
	}
	a=a*kuai(c,m);
	cout<<a.cnt[0][0];
}