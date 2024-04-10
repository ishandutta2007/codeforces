#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,l;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll f[255][255][255],pre[255][255][255],res,pw[255][255],inv[100500];
int main() {
	for(i=0;i<=252;i++){
		inv[i]=ksm(i,M-2);for(j=0;j<=252;j++)pw[i][j]=ksm(i,j);
	}
	cin>>n>>m;n--;
	f[0][0][0]=pre[0][0][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=0;k<j;k++)f[i][j][1]=su(f[i][j][1],pre[i-1][k][i-1]*pw[m-j+1][i-1]%M);
			f[i][j][1]=f[i][j][1]*(n+1-i)%M;pre[i][j][1]=f[i][j][1];
			for(l=2;l<=i;l++)f[i][j][l]=f[i-1][j][l-1]*pw[m-j+1][i-1]%M*(n+1-i)%M*inv[l]%M,pre[i][j][l]=su(pre[i][j][l-1],f[i][j][l]);
			if(i==n)res=su(res,pre[i][j][n]);
		}
	}
	cout<<res%M;
}