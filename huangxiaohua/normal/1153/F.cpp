#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,len;
int f[4050][4050],g[4050][4050];

int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main() {
	f[0][0]=1;
	cin>>n>>m>>len;
	f[0][0]=1;
	for(i=1;i<=n+n;i++){
		for(j=((i+1)/2);j<=i;j++){
			k=(j+j-(i-1));
			f[i][j]=su(f[i][j],f[i-1][j]*1ll*k%M);
			g[i][j]=su(g[i][j],g[i-1][j]*1ll*k%M);
			if(k>=m)g[i][j]=su(g[i][j],f[i-1][j]*1ll*k%M);
			
			if(j){
				f[i][j]=su(f[i][j],f[i-1][j-1]);
				g[i][j]=su(g[i][j],g[i-1][j-1]);
				if(k-2>=m)g[i][j]=su(g[i][j],f[i-1][j-1]);
			}
		}
	}
	cout<<ksm(n+n+1,M-2)*g[n+n][n]%M*len%M*ksm(f[n+n][n],M-2)%M;
}