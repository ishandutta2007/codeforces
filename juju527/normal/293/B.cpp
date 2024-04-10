#include<bits/stdc++.h>
using namespace std;
const int maxn=15,maxm=15,maxk=15,mod=1e9+7;
int n,m,k,ans=0;
int a[maxn][maxm];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
bool vis[maxn][maxm][maxk];
bool check(int x,int y){
	for(int i=1;i<=k;i++)vis[x][y][i]=(vis[x-1][y][i]|vis[x][y-1][i]);
	int sum=0;
	for(int i=1;i<=k;i++)if(!vis[x][y][i])sum++;
	if(n+m-1-(x+y-1)>=sum)return 0;
	return 1;
}
struct node{
	int x,y;
};
vector<node>p;
int use[maxk];
int dfs(int c){
	if(c==n*m)return 1;
	int x=p[c].x,y=p[c].y;
	if(!check(x,y))return 0;
	int sum=0,tmp=-1;
	if(!a[x][y]){
		for(int i=1;i<=k;i++){
			if(vis[x][y][i])continue;
			if(!use[i]){
				if(tmp==-1){
					use[i]++;
					a[x][y]=i;
					vis[x][y][i]=1;
					tmp=dfs(c+1);
					sum=add(sum+tmp);
					vis[x][y][i]=0;
					a[x][y]=0;
					use[i]--;
				}
				else sum=add(sum+tmp);
			}
			else{
				use[i]++;
				a[x][y]=i;
				vis[x][y][i]=1;
				sum=add(sum+dfs(c+1));
				vis[x][y][i]=0;
				a[x][y]=0;
				use[i]--;
			}
		}
	}
	else{
		if(vis[x][y][a[x][y]])return 0;
		vis[x][y][a[x][y]]=1;
		sum=add(sum+dfs(c+1));
		vis[x][y][a[x][y]]=0;
	}
	return sum;
}
int main(){	
	n=read();m=read();k=read();
	if(n+m-1>k){puts("0");return 0;}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){a[i][j]=read();use[a[i][j]]++;}
	for(int i=1;i<=min(n,m);i++){
		for(int j=1;j<i;j++)p.push_back((node){i,j});
		for(int j=1;j<=i;j++)p.push_back((node){j,i});
	}
	if(n>m)for(int i=m+1;i<=n;i++)for(int j=1;j<=m;j++)p.push_back((node){i,j});
	if(n<m)for(int i=1;i<=n;i++)for(int j=n+1;j<=m;j++)p.push_back((node){i,j});	
	ans=dfs(0); 
	printf("%d\n",ans);
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	return 0;
}