#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
#define M 998244353
int i,j,k,n,m,t,x,y,a1,a2;
short sb[405][405][405],dis[405][405];
vector<int> v[405];
bool used[405];
queue<int> q,q1;
ll res[405][405];

bool chk(int x,int y){
	while(!q1.empty()){q1.pop();}
	q1.push(y);
	while(!q1.empty()){
		a1=q1.front();q1.pop();
		if(x!=y){sb[x][y][a1]++;
		}
		for(auto i:v[a1]){
			if(dis[x][i]+1==dis[x][a1]){q1.push(i);}
		}
		if(q1.size()>1){return 1;}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		sb[i][i][i]=1;
		for(j=1;j<=n;j++){
			res[i][j]=1;
		}
	}
	for(i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		q.push(i);
		used[i]=1;
		while(!q.empty()){
			x=q.front();q.pop();
			for(auto j:v[x]){
				if(used[j]){continue;}
				dis[i][j]=dis[i][x]+1;
				q.push(j);used[j]=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				for(auto l:v[k]){
					a1=dis[i][l]==(dis[i][k]-1);
					a2=dis[j][l]==(dis[j][k]-1);
					if(a1&&a2){
						sb[i][j][k]++;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(chk(i,j)){res[i][j]=0;goto aaa;}
			for(k=1;k<=n;k++){
				//printf("%d %d %d %d\n",i,j,k,sb[i][j][k]);
				//if(sb[i][j][k]==0){sb[i][j][k]++;}
				res[i][j]=res[i][j]*sb[i][j][k]%M;
			}
			aaa:printf("%lld ",res[i][j]);
		}puts("");
	}
}