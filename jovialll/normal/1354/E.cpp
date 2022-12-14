#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define pb push_back
int n,m,val[N],cnt,n1,V,n2,n3,col[N],x1,x2,X1[N],X2[N];
bool dp[N][N*2];
vector < int > to[N],dot[N];
void dfs(int xx,int now){
	if(col[now]==0)++x1;else ++x2;
	dot[xx].pb(now);
	for(int i=0;i<to[now].size();++i){
		if(col[to[now][i]]==-1){
			col[to[now][i]]=1-col[now];
			dfs(xx,to[now][i]);
		}
		else if(col[to[now][i]]==col[now]){
			cout<<"NO";exit(0);
		}
	}
}
int i,x,y,j;
int main(){
	cin>>n>>m>>n1>>n2>>n3;n1+=n3;
	for(i=1;i<=m;++i)cin>>x>>y,to[x].pb(y),to[y].pb(x);
	memset(col,-1,sizeof(col));
	dp[0][n]=1;
	for(i=1;i<=n;++i){
		if(col[i]==-1){
		++cnt;
		col[i]=x1=x2=0,dfs(cnt,i);
		X1[cnt]=x1,X2[cnt]=x2;
		for(j=0;j<=n*2;++j){
	if(dp[cnt-1][j])dp[cnt][j+x1-x2]=dp[cnt][j-x1+x2]=1;
		}
		}
	}
	V=n1-n2+n;
	if(dp[cnt][V]){
		cout<<"YES\n";
		for(i=cnt;i;--i){
			if(dp[i-1][V-X1[i]+X2[i]]){
				V-=X1[i]-X2[i];
				for(j=0;j<dot[i].size();++j){
					if(col[dot[i][j]])val[dot[i][j]]=2;
					else val[dot[i][j]]=1;
				}
			}
			else {
				V-=X2[i]-X1[i];
				for(j=0;j<dot[i].size();++j){
					if(col[dot[i][j]])val[dot[i][j]]=1;
					else val[dot[i][j]]=2;
				}
			}
		}
		for(i=1;i<=n;++i){
			if(val[i]==1&&n3)--n3,val[i]=3;
			cout<<val[i];
		}
	}
	else cout<<"NO";
	return 0;
}