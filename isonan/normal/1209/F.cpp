#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

const int P=1000000007;
std::queue<std::vector<int> >q;
std::vector<int>con[2000001][10];
int n,m;
int dis[2000001];
int cnt;
void push(int s,int t,int val){
	con[s][val].push_back(t);
}
void addedge(int u,int v,int tem){
	while(tem>9){
		push(++cnt,v,tem%10);
		v=cnt;
		tem/=10;
	}
	push(u,v,tem);
}
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v,i);
		addedge(v,u,i);
	}
	memset(dis,-1,sizeof dis);
	dis[1]=0;
	q.push(std::vector<int>(1,1));
	while(!q.empty()){
		std::vector<int>now=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			std::vector<int>tem;
			for(int j=0;j<now.size();j++){
				int v=now[j];
				for(int k=0;k<con[v][i].size();k++)
					if(!~dis[con[v][i][k]]){
						dis[con[v][i][k]]=(10ll*dis[v]+1ll*i)%P;
						tem.push_back(con[v][i][k]);
					}
			}
			if(!tem.empty())q.push(tem);
		}
	}
	for(int i=2;i<=n;i++)printf("%d\n",dis[i]);
}