#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > t;
int n,k;
void dfs(int u){
	if((u<<1)>=t.size()){
		return;
	}
	dfs(u<<1);
	dfs(u<<1|1);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(t[u<<1][i]==-1||t[u<<1|1][j]==-1){
				continue;
			}
			t[u][i|j]=max(t[u][i|j],t[u<<1][i]+t[u<<1|1][j]+(i|j));
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	int d=1<<(n-1);
	t.assign(d<<1,vector<int>(4,-1));
	int x;
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		x--;
		x/=2;
		x+=d;
		if(t[x][1]!=-1){
			t[x][3]=1;
		}
		t[x][1]=1;
		t[x][2]=1;
	}
	for(int i=d;i<(d<<1);i++){
		t[i][0]=0;
		for(int j=1;j<4;j++){
			if(t[i][j]!=-1){
				t[i][0]=-1;
			}
		}
	}
	dfs(1);
	printf("%d\n",max(t[1][1],max(t[1][2],t[1][3]))+1);
	return 0;
}