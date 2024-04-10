#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,k,m,dp[505][505],xx,yy,used[505][505];
ll res;
char sb[505][505];
queue<int> x,y;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;res=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				dp[i][j]=-1;
			}
		}
		memset(sb,0,sizeof(sb));
		memset(used,0,sizeof(used));
		for(i=1;i<=n;i++){
			cin>>sb[i]+1;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(sb[i][j]=='*'){res++;}
				if(sb[i][j]=='*'&&!(sb[i][j-1]=='*'&&sb[i][j+1]=='*'&&sb[i-1][j]=='*')){
					dp[i][j]=0;used[i][j]=1;
					x.push(i);y.push(j);
				}
			}
		}
		while(!x.empty()){
			
			xx=x.front();yy=y.front();
			//printf("%d %d\n",xx,dp[xx][yy]);
			x.pop();y.pop();
			if(sb[xx+1][yy]=='*'&&!used[xx+1][yy]){
				x.push(xx+1);y.push(yy);
				dp[xx+1][yy]=dp[xx][yy]+1;
				sb[xx+1][yy]='.';
				used[xx+1][yy]=1;
				res+=dp[xx+1][yy];
			}
			
			if(sb[xx][yy+1]=='*'&&!used[xx][yy+1]){
				x.push(xx);y.push(yy+1);
				dp[xx][yy+1]=dp[xx][yy]+1;
				sb[xx][yy+1]='.';
				used[xx][yy+1]=1;
				res+=dp[xx][yy+1];
			}
			
			if(sb[xx][yy-1]=='*'&&!used[xx][yy-1]){
				x.push(xx);y.push(yy-1);
				dp[xx][yy-1]=dp[xx][yy]+1;
				sb[xx][yy-1]='.';
				used[xx][yy-1]=1;
				res+=dp[xx][yy-1];
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}