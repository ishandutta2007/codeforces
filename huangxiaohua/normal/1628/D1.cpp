#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
#define inv 500000004

int i,j,k,n,m,t;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll res,f[2050][2050];

int main() {
	ios::sync_with_stdio(0);
	for(i=1;i<=2000;i++){
		f[i][i]=i;
		for(j=i+1;j<=2000;j++){
			f[j][i]=(f[j-1][i-1]+f[j-1][i])%M*inv%M;
		}
	}
	cin>>t;
	while(t--){
		ll sb;
		cin>>n>>m>>sb;
		cout<<f[n][m]*sb%M<<'\n';
	}
}