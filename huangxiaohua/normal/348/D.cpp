#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,m2;
ll f[3050][3050],g[3050][3050];
char s[3050][3050];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]+1;
	}
	f[1][2]=(s[1][2]=='.');
	g[2][1]=(s[2][1]=='.');
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s[i][j]=='.'){
				f[i][j]+=su(f[i-1][j],f[i][j-1]);
				g[i][j]+=su(g[i-1][j],g[i][j-1]);
			}
		}
	}
	cout<<su(f[n-1][m]*g[n][m-1]%M,M-f[n][m-1]*g[n-1][m]%M);
}