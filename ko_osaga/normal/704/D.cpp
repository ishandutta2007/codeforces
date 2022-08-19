#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

const int MAXN = 222222;
struct maxflow{
	struct edg{int pos, cap, rev, idx;};
	vector<edg> gph[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++){
			gph[i].clear();
		}
	}

	void add_edge(int s, int e, int x){
		gph[s].push_back({e, x, (int)gph[e].size(), -1});
		gph[e].push_back({s, 0, (int)gph[s].size()-1, -1});
	}

	void add_edge(int s, int e, int x, int idx){
		gph[s].push_back({e, x, (int)gph[e].size(), idx});
		gph[e].push_back({s, 0, (int)gph[s].size()-1, -1});
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
			for(int i=0; i<gph[x].size(); i++){
				edg e = gph[x][i];
				if(e.cap > 0 && !dis[e.pos]){
					dis[e.pos] = dis[x] + 1;
					que.push(e.pos);
				}
			}
		}
		return dis[sink] > 0;
	}

	int dfs(int x, int sink, int f){
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
			while((r = dfs(src, sink, 2e9))) ret += r;
		}
		return ret;
	}
}maxflow;

int n, m, sx, sy;
int x[100005], y[100005];
pi nx[100005], ny[100005];

string solve(){
	int src = sx + sy;
	int snk = sx + sy + 1;
	int asrc = sx + sy + 2;
	int asnk = sx + sy + 3;
	lint s1 = 0, s2 = 0;
	for(int i=0; i<sx; i++){
		s1 += nx[i].first;
		maxflow.add_edge(asrc, i, nx[i].second - nx[i].first);
		maxflow.add_edge(asrc, snk, nx[i].first);
		maxflow.add_edge(src, i, nx[i].first);
	}
	for(int i=0; i<sy; i++){
		s2 += ny[i].first;
		maxflow.add_edge(sx + i, asnk, ny[i].second - ny[i].first);
		maxflow.add_edge(sx + i, snk, ny[i].first);
		maxflow.add_edge(src, asnk, ny[i].first);
	}
	for(int i=0; i<n; i++){
		maxflow.add_edge(x[i], y[i] + sx, 1, i);
	}
	maxflow.add_edge(asnk, asrc, 1e9);
	if(maxflow.match(src, snk) != s1 + s2) return "-1";
	maxflow.match(asrc, asnk);
	string ret(n, 'a');
	for(int i=0; i<sx; i++){
		for(auto &j : maxflow.gph[i]){
			if(j.idx != -1){
				if(j.cap == 0) ret[j.idx] = 'b';
				else ret[j.idx] = 'r';
			}
		}
	}
	return ret;
}

int cnt1[100005], cnt2[100005];

int main(){
	vector<int> vx, vy;
	int r, b;
	cin >> n >> m >> r >> b;
	for(int i=0; i<n; i++){
		scanf("%d %d",&x[i],&y[i]);
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for(int i=0; i<n; i++){
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
		y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
		nx[x[i]].second++;
		ny[y[i]].second++;
		cnt1[x[i]]++;
		cnt2[y[i]]++;
	}	
	sx = vx.size();
	sy = vy.size();
	for(int i=0; i<m; i++){
		int t, l, d;
		scanf("%d %d %d",&t,&l,&d);
		if(t == 1){
			auto p = lower_bound(vx.begin(), vx.end(), l);
			if(p == vx.end() || *p != l) continue;
			int idx = p - vx.begin();
			nx[idx].first = max(nx[idx].first, (cnt1[idx] - d + 1) / 2);
			nx[idx].second = min(nx[idx].second, (cnt1[idx] + d) / 2);
			if(nx[idx].first > nx[idx].second){
				puts("-1");
				return 0;
			}
		}
		else{
			auto p = lower_bound(vy.begin(), vy.end(), l);	
			if(p == vy.end() || *p != l) continue;
			int idx = p - vy.begin();
			ny[idx].first = max(ny[idx].first, (cnt2[idx] - d + 1) / 2);
			ny[idx].second = min(ny[idx].second, (cnt2[idx] + d) / 2);
			if(ny[idx].first > ny[idx].second){
				puts("-1");
				return 0;
			}
		}
	}
	auto w = solve();
	if(w == "-1"){
		puts("-1");
		return 0;
	}
	if(r < b){
		for(auto &i : w) i ^= ('r' ^ 'b');
	}
	lint ret = 0;
	for(auto &i : w){
		if(i == 'r') ret += r;
		else ret += b;
	}
	printf("%lld\n", ret);
	cout << w << endl;
}