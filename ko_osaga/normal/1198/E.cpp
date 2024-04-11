#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 505;
const int mod = 1e9 + 7;
#define has(msk, v) (((msk) >> (v)) & 1)

struct mf{
	struct edg{ int pos; lint cap; int rev; };
vector<edg> gph[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, lint x){
	gph[s].push_back({e, x, (int)gph[e].size()});
	gph[e].push_back({s, 0, (int)gph[s].size()-1});
}
int dis[MAXN], pnt[MAXN];
bool bfs(int src, int sink){
	memset(dis, 0, sizeof(dis));
	memset(pnt, 0, sizeof(pnt));
	queue<int> que;
	que.push(src);
	dis[src] = 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &e : gph[x]){
			if(e.cap > 0 && !dis[e.pos]){
				dis[e.pos] = dis[x] + 1;
				que.push(e.pos);
			}
		}
	}
	return dis[sink] > 0;
}
lint dfs(int x, int sink, lint f){
	if(x == sink) return f;
	for(; pnt[x] < gph[x].size(); pnt[x]++){
		edg e = gph[x][pnt[x]];
		if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
			int w = dfs(e.pos, sink, min(f, e.cap));
			if(w){
				gph[x][pnt[x]].cap -= w;
				gph[e.pos][e.rev].cap += w;
				return w;
			}
		}
	}
	return 0;
}
lint match(int src, int sink){
	lint ret = 0;
	while(bfs(src, sink)){
		int r;
		while((r = dfs(src, sink, 1e10))) ret += r;
	}
	return ret;
}
}mf;

int n, m;
int arr[MAXN][MAXN];
struct rect{
	int sx, ex, sy, ey, idx;
}a[MAXN];
vector<int> vx, vy;


int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> a[i].sx >> a[i].sy >> a[i].ex >> a[i].ey;
		vx.push_back(a[i].sx);
		vx.push_back(a[i].ex + 1);
		vy.push_back(a[i].sy);
		vy.push_back(a[i].ey + 1);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for(int i=0; i<m; i++){
		int sx = lower_bound(vx.begin(), vx.end(), a[i].sx) - vx.begin();
		int ex = lower_bound(vx.begin(), vx.end(), a[i].ex + 1) - vx.begin();
		int sy = lower_bound(vy.begin(), vy.end(), a[i].sy) - vy.begin();
		int ey = lower_bound(vy.begin(), vy.end(), a[i].ey + 1) - vy.begin();
		for(int j=sx; j<ex; j++){
			for(int k=sy; k<ey; k++){
				arr[j][k] = 1;
			}
		}
	}
	for(int i=1; i<vx.size(); i++){
		mf.add_edge(0, i, vx[i] - vx[i-1]);
	}
	for(int i=1; i<vy.size(); i++){
		mf.add_edge(200 + i, 500, vy[i] - vy[i-1]);
	}
	for(int i=1; i<vx.size(); i++){
		for(int j=1; j<vy.size(); j++){
			if(arr[i-1][j-1]){
				lint cost = 1ll * (vx[i] - vx[i-1]) * (vy[j] - vy[j-1]);
				mf.add_edge(i, 200 + j, cost);
			}
		}
	}
	cout << mf.match(0, 500) << endl;
}