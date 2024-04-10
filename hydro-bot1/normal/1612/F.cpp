// Hydro submission #6321d0b1bdf9bc31d15fd8e1@1663160498099
#include<bits/stdc++.h>
using namespace std;
#define maxn 200009
int n,m,q,dp[maxn][31];
std::map<int ,bool > qwq[maxn];
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();m=read();
	bool flag=false;
	if(n>m)swap(n,m),flag=true;
	q=read();
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		if(flag)swap(x,y);
		qwq[x][y]=true;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=30;j++){
			dp[i][j]=-1e9;
		}
	}
	dp[1][0]=1;
	for(int i=0;i<=29;i++){
		for(int j=1;j<=n;j++){
			if(dp[j][i]!=-1e9){
				int nxt=j+dp[j][i]+qwq[j].count(dp[j][i]);
				dp[min(n,nxt)][i+1]=max(dp[min(n,nxt)][i+1],dp[j][i]);
				dp[j][i+1]=max(dp[j][i+1],nxt);
			}
		} 
	}
	int ans=1e9;
	for(int i=0;i<=30;i++){
		if(dp[n][i]!=-1e9){
			if(dp[n][i]<m){
				int cnt=i,j=dp[n][i];
				while(j<m){
					j+=qwq[n].count(j);
					j+=n;
					cnt++;
				}
				ans=min(ans,cnt);
			}
			else ans=min(ans,i);
		}
	}
	cout<<ans<<endl;
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}