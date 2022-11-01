#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int k;
vector<int> v1[maxn], v2[maxn];
int x, y;
queue<int> q;
bool inq[maxn];
int p[maxn];
int dis[maxn];
int mx, mn;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v2[y].push_back(x);
	}
	scanf("%d", &k);
	for(int i = 1;i <= k;i++) scanf("%d", &p[i]);
	memset(dis, 0x3f, sizeof(dis)), dis[p[k]] = 0, q.push(p[k]), inq[p[k]] = true;
	while(!q.empty()){
		x = q.front(), q.pop(), inq[x] = false;
		for(int i = 0;i < v2[x].size();i++){
			if(dis[x] + 1 < dis[v2[x][i]]){
				dis[v2[x][i]] = dis[x] + 1;
				if(!inq[v2[x][i]]) inq[v2[x][i]] = true, q.push(v2[x][i]);
			}
		}
	}
	//for(int i = 1;i <= k;i++) printf("%d--\n", dis[p[i]]);
	for(int i = 1;i < k;i++){
		if(dis[p[i]] - dis[p[i + 1]] != 1){
			mx++, mn++;
		}else{
			for(int j = 0;j < v1[p[i]].size();j++){
				if(v1[p[i]][j] != p[i + 1] && dis[p[i]] - dis[v1[p[i]][j]] == 1){
					mx++;
					break;
				}
			}
		}
	}
	printf("%d %d", mn, mx);
}