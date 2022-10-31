#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t,a[105],x,y;
double dis[105][105],sb;
vector<int> v[105];

struct sb{
	int id,x,y;
}s[105];

void dfs(int x,int fa){
	int sb=0;
	if(x==1){
		for(auto i:v[x]){
			dis[i][x]=2.0/a[x]*sb;
			while(dis[i][x]>=2.0){
				dis[i][x]-=2.0;
			}
			
			if(dis[i][x]<=1.0){
				dis[x][i]=dis[i][x]+1;
			}
			else{
				dis[x][i]=dis[i][x]-1;
			}
			sb++;
		}
	}
	else{
		double tmp=dis[fa][x];
		for(auto i:v[x]){
			if(i==fa)continue;
			sb++;
			dis[i][x]=tmp+2.0/a[x]*sb;
			while(dis[i][x]>=2.0){
				dis[i][x]-=2.0;
			}
			
			if(dis[i][x]<=1.0){
				dis[x][i]=dis[i][x]+1;
			}
			else{
				dis[x][i]=dis[i][x]-1;
			}
		}
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
		s[i].x=j;
		s[i].y=k;
		a[j]++;a[k]++;
	}
	dfs(1,0);
	printf("%d\n",n-1);
	for(i=1;i<n;i++){
		printf("1 %d ",i);
		x=s[i].x;
		y=s[i].y;
		if(dis[x][y]<=1.0){
			printf("%d %d %.20lf\n",x,y,1-dis[x][y]);
		}
		else{
			printf("%d %d %.20lf\n",y,x,1-dis[y][x]);
		}
	}
}