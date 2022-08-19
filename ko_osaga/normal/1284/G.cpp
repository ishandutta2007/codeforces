#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 805;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int n, m;
char str[25][25];
int idx[25][25], piv;
char ans[50][50];
int needy[MAXN];
vector<pi> v;

int adj[MAXN][MAXN];
int par[MAXN], dist[MAXN], indep[MAXN];

void matroid_intersection(){
	int cnt[MAXN] = {};
	memset(indep, 0, sizeof(indep));
	while(true){
		bool found = 0;
		disj.init(piv);
		for(int i=0; i<sz(v)+2; i++){
		    cnt[i] = 0;
		    for(int j=0; j<sz(v)+2; j++){
		        adj[i][j] = 0;
		    }
		}
		for(int i=0; i<sz(v); i++){
			if(indep[i]){
				disj.uni(v[i].first, v[i].second);
				cnt[v[i].first]++;
				cnt[v[i].second]++;
			}
		}
		for(int i=0; i<sz(v); i++){
			if(!indep[i]){
				bool p1 = disj.find(v[i].first) != disj.find(v[i].second);
				bool p2 = (cnt[v[i].first] < needy[v[i].first]) && (cnt[v[i].second] < needy[v[i].second]);
				if(p1 && p2){
					indep[i] = 1;

					found = 1;
					break;
				}
				if(p1) adj[sz(v)][i] = 1;
				if(p2) adj[i][sz(v) + 1] = 1;
			}
		}
		if(found) continue;
		for(int i=0; i<sz(v); i++){
			if(indep[i]){
				disj.init(piv);
				for(int j=0; j<sz(v); j++) cnt[j] = 0;
				for(int j=0; j<sz(v); j++){
					if(i != j && indep[j]) disj.uni(v[j].first, v[j].second);
				}
				for(int j=0; j<sz(v); j++){
					if(!indep[j] && disj.find(v[j].first) != disj.find(v[j].second)) adj[i][j] = 1;
				}
				for(int j=0; j<sz(v); j++){
					if(i != j && indep[j]){
						cnt[v[j].first]++;
						cnt[v[j].second]++;
					}
				}
				for(int j=0; j<sz(v); j++){
					if(!indep[j] && 
						cnt[v[j].first] < needy[v[j].first] &&
						cnt[v[j].second] < needy[v[j].second]){
						adj[j][i] = 1;
					}
				}
			}
		}
		queue<int> que;
		memset(dist, 0x3f, sizeof(dist));
		que.push(sz(v)); dist[sz(v)] = 0;
		while(sz(que)){
			int x = que.front(); que.pop();
			for(int i=0; i<sz(v) + 2; i++){
				if(dist[i] > dist[x] + 1 && adj[x][i]){
					dist[i] = dist[x] + 1;
					par[i] = x;
					que.push(i);
				}
			}
		}
		if(dist[sz(v) + 1] > 1e8) break;
		for(int j=sz(v) + 1; j!=sz(v); j=par[j]){
			if(j < sz(v)) indep[j] ^= 1;
		}
	}
}

bool has_edge(int x, int y){
	for(int i=0; i<sz(v); i++){
		if(indep[i] && (v[i] == pi(x, y) || v[i] == pi(y, x))) return 1;
	}
	return 0;
}

void solve(){
	cin >> n >> m;
	int cnt = 0;
	for(int i=0; i<n; i++){
		cin >> str[i];
		for(int j=0; j<m; j++){
			if(str[i][j] == 'O'){
				idx[i][j] = ++piv;
				if(i + j > 0 && i % 2 == j % 2) needy[piv] = 2, cnt++;
				else needy[piv] = 4;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i + j == 0) continue;
			if(j+1 < m && str[i][j] == 'O' && str[i][j+1] == 'O'){
				int l = idx[i][j];
				int r = idx[i][j+1];
				v.emplace_back(l, r);
			}
			if(i+1 < n && str[i][j] == 'O' && str[i+1][j] == 'O'){
				int l = idx[i][j];
				int r = idx[i+1][j];
				v.emplace_back(l, r);
			}
		}
	}
	matroid_intersection();
	if(count(indep, indep + sz(v), 1) < 2 * cnt){
		puts("NO");
		return;
	}
	if(str[0][1] == 'O') v.emplace_back(idx[0][0], idx[0][1]);
	if(str[1][0] == 'O') v.emplace_back(idx[0][0], idx[1][0]);
	disj.init(piv);
	for(int i=0; i<sz(v); i++){
		if(indep[i]) assert(disj.uni(v[i].first, v[i].second));
	}
	for(int i=0; i<sz(v); i++){
		if(disj.uni(v[i].first, v[i].second)) indep[i] = 1;
	}
	puts("YES");
	for(int i=0; i<2*n-1; i++){
		for(int j=0; j<2*m-1; j++){
			ans[i][j] = ' ';
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ans[2*i][2*j] = str[i][j];
			if(has_edge(idx[i][j], idx[i][j+1])) ans[2*i][2*j+1] = 'O';
			if(has_edge(idx[i][j], idx[i+1][j])) ans[2*i+1][2*j] = 'O';
		}
	}
	for(int i=0; i<2*n-1; i++) puts(ans[i]);
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
		piv = 0;
		memset(idx, 0, sizeof(idx));
		memset(needy, 0, sizeof(needy));
		memset(ans, 0, sizeof(ans));
		v.clear();
	}
}