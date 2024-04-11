#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

struct edg{
	int pos, idx;
	lint cst;
	bool operator<(const edg &e)const{
		return cst > e.cst;
	}
};

int n, m, l, s, t;
vector<edg> g1[1005], g2[1005];
lint d1[1005][1005], d2[1005][1005];
int pa[1005][1005], pe[1005][1005];

void dijkstra(int s){
	priority_queue<edg> pq;
	d1[s][s] = d2[s][s] = 0;
	pq.push({s, 0, 0});
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(d1[s][x.pos] < x.cst) continue;
		for(auto &i : g1[x.pos]){
			if(i.cst + x.cst < d1[s][i.pos]){
				d1[s][i.pos] = i.cst + x.cst;
				pq.push({i.pos, 0, i.cst + x.cst});
			}
		}
	}
	pq.push({s, 0, 0});
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(d2[s][x.pos] < x.cst) continue;
		for(auto &i : g2[x.pos]){
			if(i.cst + x.cst < d2[s][i.pos]){
				pa[s][i.pos] = x.pos;
				pe[s][i.pos] = i.idx;
				d2[s][i.pos] = i.cst + x.cst;
				pq.push({i.pos, 0, i.cst + x.cst});
			}
		}
	}
}

int as[10005], ae[10005], ax[10005], choggy[10005];
int main(){
	cin >> n >> m >> l >> s >> t;
	for(int i=1; i<=m; i++){
		int s, e, x;
		cin >> s >> e >> x;
		tie(as[i], ae[i], ax[i]) = make_tuple(s, e, x);
		if(x > 0){
			choggy[i] = 1;
			g1[s].push_back({e, i, x});
			g1[e].push_back({s, i, x});
			g2[s].push_back({e, i, x});
			g2[e].push_back({s, i, x});
		}
		else{
			g2[s].push_back({e, i, 1});
			g2[e].push_back({s, i, 1});
		}
	}
	memset(d1, 0x3f, sizeof(d1));
	memset(d2, 0x3f, sizeof(d2));
	for(int i=0; i<n; i++){
		dijkstra(i);
	}
	if(d1[s][t] < l || (d1[s][t] > l && d2[s][t] > l)){
		puts("NO");
		return 0;
	}
	if(d1[s][t] == l){
		puts("YES");
		for(int i=1; i<=m; i++){
			if(ax[i] == 0) ax[i] = 2e9;
			printf("%d %d %d\n", as[i], ae[i], ax[i]);
		}
		return 0;
	}
	vector<int> trace;
	int residue = l - d2[s][t];
	for(int i=t; i!=s; i=pa[s][i]){
		if(ax[pe[s][i]] == 0) ax[pe[s][i]] = 1;
		trace.push_back(pe[s][i]);
	}
	while(d2[s][t] < l){
		fprintf(stderr,"%lld\n", d2[s][t]);
		vector<int> trace;
		for(int i=t; i!=s; i=pa[s][i]){
			if(choggy[pe[s][i]] == 0){
				if(ax[pe[s][i]] == 0) ax[pe[s][i]] = 1;
				int v = l - d2[s][t];
				int edgn = pe[s][i];
				if(ax[edgn] == 0) ax[edgn]++;
				ax[edgn] += v;
				for(auto &i : g2[as[edgn]]){
					if(i.idx == edgn) i.cst += v;
				}
				for(auto &i : g2[ae[edgn]]){
					if(i.idx == edgn) i.cst += v;
				}
				break;
			}
		}
		memset(d2[s], 0x3f, sizeof(d2[s]));
		dijkstra(s);
	}
	puts("YES");
	for(int i=1; i<=m; i++){
		if(ax[i] == 0) ax[i] = 2e9;
		printf("%d %d %d\n", as[i], ae[i], ax[i]);
	}
	return 0;
}