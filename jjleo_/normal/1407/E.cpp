#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, m;
int x, y, z;
vector<pair<int, int> > v[maxn];
int dis[maxn][2];
queue<int> q;
bool inq[maxn];

int main(){
	scanf("%d%d", &n, &m);
	memset(dis, 0x3f, sizeof(dis));
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[y].push_back({x, z});
	}
	dis[n][0] = dis[n][1] = 0, q.push(n), inq[n] = true;
	while(!q.empty()){
		int x = q.front();q.pop();
		inq[x] = false;
		int d = max(dis[x][0], dis[x][1]);
		for(int i = 0;i < v[x].size();i++){
			int tox = v[x][i].first, toy = v[x][i].second;
			if(dis[tox][toy] > d + 1){
				if(max(dis[tox][toy], dis[tox][toy ^ 1]) > max(d + 1, dis[tox][toy ^ 1])){
					if(!inq[tox]) q.push(tox), inq[tox] = true;
				}
				dis[tox][toy] = d + 1;
			}
		}
	}
	printf("%d\n", max(dis[1][0], dis[1][1]) == 0x3f3f3f3f ? -1 : max(dis[1][0], dis[1][1]));
	for(int i = 1;i <= n;i++) printf("%d", dis[i][0] > dis[i][1] ? 0 : 1);
}