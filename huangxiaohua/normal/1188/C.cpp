#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int i,j,k,n,m,t,a[1050],f[1050][1005],res[100500],sb,nxt[1050];
ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=(100000+m-2)/(m-1);i>=1;i--){
		for(j=1;j<=n;j++){
			while(nxt[j]<j-1&&a[j]-a[nxt[j]+1]>=i)nxt[j]++;
			memset(f[j],0,m*4+10);
		}
		for(j=1;j<=n;j++)f[1][j]=j;
		for(j=2;j<=m;j++){
			for(k=1;k<=n;k++)f[j][k]=su(f[j][k-1],f[j-1][nxt[k]]);
		}
		res[i]=f[m][n];
		ans+=1ll*i*su(res[i],M-res[i+1])%M;ans%=M;
		for(j=1;j<=n;j++)memset(f[j],0,m*4+10);
	}
	printf("%lld",ans);
}