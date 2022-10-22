#include<bits/stdc++.h>
using namespace std;
int n,m,k,num=0,ans;
int b[509][509],c[509][509],dp[509][509][13],vis[509][509][13];
bool in[509][509][13];
bool pd(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
bool push(int x,int y,int z,int v){
	if(dp[x][y][z]>v){
		dp[x][y][z]=v;
		return !in[x][y][z];
	}
	return 0;
}
struct P{int x,y,z;};
void bfs(){
	queue<P>q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int z=1;z<=k;++z)dp[i][j][z]=1e9;
			q.push(P{i,j,0});
		}
	}
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,z=q.front().z;
		in[x][y][z]=0;
		q.pop();
		if(z==k)continue;
	//	if(z)cout<<x<<" "<<y<<" "<<z<<" "<<dp[x][y][z]<<endl;
		if(pd(x-1,y)){
			if(push(x-1,y,z+1,dp[x][y][z]+c[x-1][y])){
				in[x-1][y][z+1]=1;
				q.push(P{x-1,y,z+1});
			}
		}
		if(pd(x+1,y)){			
			if(push(x+1,y,z+1,dp[x][y][z]+c[x][y])){
				in[x+1][y][z+1]=1;
				q.push(P{x+1,y,z+1});
			}
		}
		if(pd(x,y-1)){
			if(push(x,y-1,z+1,dp[x][y][z]+b[x][y-1])){
				in[x][y-1][z+1]=1;
				q.push(P{x,y-1,z+1});
			}
		}
		if(pd(x,y+1)){
			if(push(x,y+1,z+1,dp[x][y][z]+b[x][y])){
				in[x][y+1][z+1]=1;
				q.push(P{x,y+1,z+1});
			}
		}
	}
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
    	for(int j=1;j< m;++j)scanf("%d",&b[i][j]);
    for(int i=1;i< n;++i)
    	for(int j=1;j<=m;++j)scanf("%d",&c[i][j]);	
    if(k&1){
    	for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j)printf("-1 ");
    		printf("\n");
		}
		return 0;
	}
	k/=2;
	bfs();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)printf("%d ",dp[i][j][k]*2);
		printf("\n");
	}
	return 0;
}
/*
4 1 20
100
100
1
*/