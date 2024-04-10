#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=1000;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef long long ll;
int n,m,T;
char s[Maxn+5][Maxn+5];
int t[Maxn+5][Maxn+5];
queue<pair<int,int> > q;
void bfs(){
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[i][j]!=-1){
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=u.first+d[i][0],ny=u.second+d[i][1];
			if(nx<1||ny<1||nx>n||ny>m||t[nx][ny]!=-1){
				continue;
			}
			t[nx][ny]=t[u.first][u.second]+1;
			q.push(make_pair(nx,ny));
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			s[i][j]-='0';
		}
	}
	memset(t,-1,sizeof t);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(nx<1||ny<1||nx>n||ny>m){
					continue;
				}
				if(s[nx][ny]==s[i][j]){
					t[i][j]=0;
				}
			}
		}
	}
	bfs();
	while(T--){
		int x,y;
		ll p;
		scanf("%d%d",&x,&y);
		cin>>p;
		if(t[x][y]==-1){
			printf("%d\n",s[x][y]);
		}
		else{
			if(p<=t[x][y]){
				printf("%d\n",s[x][y]);
			}
			else{
				if((p-t[x][y])&1){
					printf("%d\n",s[x][y]^1);
				}
				else{
					printf("%d\n",s[x][y]);
				}
			}
		}
	}
	return 0;
}