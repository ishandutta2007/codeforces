#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=110,mod=1e9+7;
int i,j,k,n,m,T;
ll dp[maxn][maxn][maxn],L[maxn][maxn],R[maxn][maxn],ans[maxn],len[maxn],Pow[maxn];
string S;
int main(){
	cin>>n>>m;
	cin>>S;
	Pow[0]=Pow[1]=2;
	for(i=1;i<=n;i++)
		if(S[i-1]=='0'){
			dp[0][i][i]=1;
			if(i==1)L[0][i]=1;
			if(i==n)R[0][i]=1;
			if(n==1)ans[0]=1;
		}else{
			dp[1][i][i]=1;
			if(i==1)L[1][i]=1;
			if(i==n)R[1][i]=1;
			if(n==1)ans[1]=1;
		}
	len[0]=len[1]=1;
	for(i=2;i<=m;i++){
		Pow[i]=Pow[i-1]*Pow[i-2]%mod;
		len[i]=len[i-1]+len[i-2];len[i]%=mod;
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++)
				dp[i][l][r]=(dp[i-1][l][r]+dp[i-2][l][r])%mod;
		for(int j=1;j<=n;j++)
			L[i][j]=(L[i-1][j]+L[i-2][j]*Pow[i-1])%mod,
			R[i][j]=(R[i-1][j]*Pow[i-2]+R[i-2][j])%mod;
		ans[i]=(ans[i-1]*Pow[i-2]+ans[i-2]*Pow[i-1])%mod;
		for(int l=1;l<=n;l++)
			for(int Mid=l;Mid<=n;Mid++)
				for(int r=Mid+1;r<=n;r++){
					if(l==1){
						if(r==n){
							ans[i]+=L[i-1][Mid]*R[i-2][Mid+1]%mod;
							ans[i]%=mod;
						}
						L[i][r]+=L[i-1][Mid]*dp[i-2][Mid+1][r]%mod;L[i][r]%=mod;
					}
					if(r==n){
						R[i][l]+=R[i-2][Mid+1]*dp[i-1][l][Mid]%mod;R[i][l]%=mod;
					}
					dp[i][l][r]+=dp[i-1][l][Mid]*dp[i-2][Mid+1][r]%mod;dp[i][l][r]%=mod;
				}
		//cout<<"OK i="<<i<<endl;
		//cout<<"dp:"<<endl;
		/*
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++)
				cout<<"dp["<<l<<"]["<<r<<"]="<<dp[i][l][r]<<endl;
		cout<<"L:"<<endl;
		for(int j=1;j<=n;j++)
			cout<<"L["<<j<<"]="<<L[i][j]<<endl;
		cout<<"R:"<<endl;
		for(int j=1;j<=n;j++)
			cout<<"R["<<j<<"]="<<R[i][j]<<endl;
		cout<<"ans:"<<ans[i]<<endl<<endl<<endl;
		*/
	}
	cout<<ans[m]<<endl;
}
/*
0
1
10
101
10110
*/