#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1005,mo=1e9+7;
int n,m,ans;
int bz[N][N];
int rcnt[N],ccnt[N],pre[N],suf[N];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char c[N][N];
void dfs(int x,int y){
	bz[x][y]=1;
	fo(i,0,3){
		int xx=x+dir[i][0],yy=y+dir[i][1];
		if(!bz[xx][yy]&&c[xx][yy]=='#')
			dfs(xx,yy);
	}
}
bool ck(){
	fo(i,1,n)fo(j,1,m)
		if(c[i][j]=='#')
			rcnt[i]++,ccnt[j]++;
	int kr=0,kc=0;
	fo(i,1,n)kr+=!rcnt[i];
	fo(i,1,m)kc+=!ccnt[i];
	if(!kr&&kc||!kc&&kr)return 1;
	fo(i,1,n){
		c[i][0]='.';
		int cnt=0;
		fo(j,1,m)if(c[i][j]=='#'&&c[i][j-1]=='.')++cnt;
		if(cnt>1)return 1;
	}
	fo(i,1,m){
		c[0][i]='.';
		int cnt=0;
		fo(j,1,n)if(c[j][i]=='#'&&c[j-1][i]=='.')++cnt;
		if(cnt>1)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
		scanf("\n%s",c[i]+1);
	fo(i,0,n+1)bz[i][0]=bz[i][m+1]=1;
	fo(i,0,m+1)bz[0][i]=bz[n+1][i]=1;
	fo(i,1,n)fo(j,1,m)if(c[i][j]=='#'&&!bz[i][j])
		++ans,dfs(i,j);
	if(ck())ans=-1;
	printf("%d\n",ans);
}