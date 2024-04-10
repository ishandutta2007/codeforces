#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;
int i,j,k,n,m;
ll f[505][505],c[1050][1050],inv[1050],ans[2]={1};
ll c2(int n,int m){ll res=1;for(int i=1;i<=m;i++){res=res*inv[i]%M*(n+1-i)%M;}return res;}
int main(){
	inv[1]=1;for(int i=2;i<=1005;i++){inv[i]=(M-M/i)*inv[M%i]%M;}
	for(i=1;i<=500;i++){f[i][0]=1;for(j=1;j<=500;j++){f[i][j]=(f[i-1][j-1]*(i-1)+f[i-1][j])%M;}}
	for(i=1,c[0][0]=1;i<=1000;i++){c[i][0]=1;for(j=1;j<=1000;j++){c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;}}
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		for(j=1;j<=min(n,i*2);j++){
			ll tmp=0;for(k=0;k<=j;k++){tmp=(tmp+M+((k&1)?-1:1)*f[j-k][i]*c[j][k]%M)%M;}
			ans[i&1]=(ans[i&1]+c2(n,j)*tmp)%M;
		}
		printf("%lld ",ans[i&1]);
	}
}