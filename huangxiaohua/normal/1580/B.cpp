#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,M;
ll c[205][205],f[105][105][105];

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

ll dp(ll n,ll d,ll t){
	if(!n)return !t;
	if(d>m&&t)return 0;
	if(t&&(n-m+d)<t)return 0;
	if(~f[n][d][t])return f[n][d][t];
	if(t+t>n+1)return 0;
	int i,j;
	ll tmp,t1,t2;
	f[n][d][t]=0;
	for(i=0;i+i<=n-1;i++){
		for(j=0;j<=t-(d==m);j++){
			t1=dp(i,d+1,j);
			if(!t1)continue;
			t2=dp(n-1-i,d+1,t-j-(d==m));
			tmp=t1*t2%M*c[n-1][i]%M;
			f[n][d][t]=su(f[n][d][t],tmp);
			if(i+i!=n-1){
				f[n][d][t]=su(f[n][d][t],tmp);
			}
		}
	}
	return f[n][d][t];
}

int main(){
	memset(f,-1,sizeof(f));
	c[0][0]=1;
	cin>>n>>m>>t>>M;
	for(i=1;i<=200;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++){
			c[i][j]=su(c[i-1][j-1],c[i-1][j]);
		}
	}
	cout<<dp(n,1,t);
}