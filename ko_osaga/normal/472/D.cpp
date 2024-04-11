#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct disj{
	int pa[2005];
	void init(int n){
		for(int i=0; i<n; i++) pa[i] = i;
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

vector<int> gph[2005];
int n, a[2005][2005];
vector<pi> e;

void dfs(int pos, int src, lint w, int p){
	if((a[pos][src] != w || a[src][pos] != w)){
		puts("NO");
		exit(0);
	}
	for(auto &i : gph[pos]){
		if(i != p) dfs(i, src, w + a[pos][i], pos);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
			if(i != j && !a[i][j]){
				puts("NO");
				return 0;
			}
			if(i > j) e.push_back({i, j});
		}
	}
	sort(e.begin(), e.end(), [&](const pi &p, const pi &q){
		return a[p.first][p.second] < a[q.first][q.second];
	});
	disj.init(n);
	for(auto &i : e){
		if(disj.uni(i.first, i.second)){
			gph[i.first].push_back(i.second);
			gph[i.second].push_back(i.first);
		}
	}
	for(int i=0; i<n; i++){
		dfs(i, i, 0, -1);
	}
	puts("YES");
}