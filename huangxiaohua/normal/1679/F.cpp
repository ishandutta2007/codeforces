#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
#define b(x) (1<<((x)))

int i,j,k,m,n,t,a[66][66],mp[2050][20],msk;
ll f[2050]={1},g[2050],res;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		a[j][k]=a[k][j]=1;
	}
	for(i=0;i<1024;i++)for(j=0;j<=9;j++)for(k=0;k<=9;k++)if((k<j||i&b(k))&&a[j][k])mp[i][j]|=b(k);
	for(i=1;i<=n;i++){
		memset(g,0,sizeof(g));
		for(j=0;j<1024;j++)if(f[j])for(k=0;k<=9;k++){
			if(b(k)&j)continue;
			g[mp[j][k]]=su(g[mp[j][k]],f[j]);
		}
		memcpy(f,g,sizeof(f));
	}
	for(i=0;i<1024;i++)res=su(res,f[i]);
	cout<<res;
}