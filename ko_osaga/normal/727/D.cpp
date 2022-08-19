#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

const int MAXN = 100050;
struct maxflow{
	struct edg{int pos, cap, rev;};
	vector<edg> gph[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++){
			gph[i].clear();
		}
	}

	void add_edge(int s, int e, int x){
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
 
int n, a[66];
char buf[16];

int solve(string s){
	if(s == "S") return 1;
	if(s == "M") return 2;
	if(s == "L") return 3;
	if(s == "XL") return 4;
	if(s == "XXL") return 5;
	return 6;
}

string solve2(int x){
	if(x == 1) return "S";
	if(x == 2) return "M";
	if(x == 3) return "L";
	if(x == 4) return "XL";
	if(x == 5) return "XXL";
	return "XXXL";
}

int main(){
	for(int i=1; i<=6; i++) cin >> a[i], maxflow.add_edge(0, i, a[i]);
	cin >> n;
	for(int i=7; i<=n+6; i++){
		scanf("%s", buf);
		int brk = -1;
		for(int i=0; buf[i]; i++){
			if(buf[i] == ',') brk = i;
		}
		if(brk == -1){
			string s;
			for(int i=0; buf[i]; i++){
				s.push_back(buf[i]);
			}
			maxflow.add_edge(solve(s), i, 1);
		}
		else{
			string s, t;
			for(int i=0; i<brk; i++){
				s.push_back(buf[i]);
			}
			for(int i=brk+1; buf[i]; i++){
				t.push_back(buf[i]);
			}
			maxflow.add_edge(solve(s), i, 1);
			maxflow.add_edge(solve(t), i, 1);
		}
		maxflow.add_edge(i, n+7, 1);
	}
	if(maxflow.match(0, n+7) == n){
		puts("YES");
		for(int i=7; i<=n+6; i++){
			for(auto &j : maxflow.gph[i]){
				if(j.pos <= 6 && j.cap == 1){
					printf("%s\n", solve2(j.pos).c_str());
				}
			}
		}
	}
	else{
		puts("NO");
	}
}