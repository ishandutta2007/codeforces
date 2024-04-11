#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, k, w;
char str[1005][11][11];
int adj[1005][1005];

struct edg{ int s, e, x; };
struct disj{
	int pa[1005];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

vector<int> gph[1005];

void dfs(int x, int p){
	if(x != 0) printf("%d %d\n", x, p);
	for(auto &i : gph[x]){
		if(i != p) dfs(i, x);
	}
}

int main(){
	cin >> n >> m >> k >> w;
	for(int i=1; i<=k; i++){
		for(int j=0; j<n; j++){
			cin >> str[i][j];
		}
	}
	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			for(int a=0; a<n; a++){
				for(int b=0; b<m; b++){
					if(str[i][a][b] != str[j][a][b]){
						adj[i][j]++;
					}
				}
			}
			adj[i][j] *= w;
		}
		adj[0][i] = adj[i][0] = n*m;
	}
	vector<edg> v;
	for(int i=0; i<=k; i++){
		for(int j=0; j<i; j++){
			v.push_back({i, j, adj[i][j]});
		}
	}
	sort(v.begin(), v.end(), [&](const edg &a, const edg &b){
		return a.x < b.x;
	});
	disj.init(k);
	int ret = 0;
	for(auto &i : v){
		if(disj.uni(i.s, i.e)){
			ret += i.x;
			gph[i.s].push_back(i.e);
			gph[i.e].push_back(i.s);
		}
	}
	cout << ret << endl;
	dfs(0, -1);
}