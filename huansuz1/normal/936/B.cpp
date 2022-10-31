#include <bits/stdc++.h>
using namespace std;

const int N = int(2e5);

int d[N][3],n,m;

vector <int> g[N], ans;   

int p[N][3], s, cyc, c[N];

int calc(int v,int t){
	if(d[v][t] != -1){
		return d[v][t];
	}
	if(g[v].size() == 0){
		return t;
	}
	d[v][t] = 0;
	for(int i = 0; i < g[v].size(); i++){
	    int to = g[v][i];
	    if(calc(to, 1 - t)){
	    	d[v][t] = 1;
	    	p[v][t] = to;
	    	break;
	    }
	}
	return d[v][t];
}

void dfs(int v){
	c[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(c[to]){
			if(c[to] == 1){
				cyc = 1;
				break;
			}
			continue;
		}
		dfs(to);
	}
	c[v] = 2;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1,k; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0,x; j < k; j++){
			scanf("%d", &x);
			g[i].push_back(x);
		}	
	}
	scanf("%d", &s);
	memset(d, -1, sizeof(d));
	int win = calc(s,0);
	if(win == 1){
		puts("Win");
		int tp = 0;
		while(true){
			ans.push_back(s);
			if((int)g[s].size() == 0) break;
			s = p[s][tp];
			tp = 1 - tp;
		}
		//printf("%d\n", int(ans.size()));
		for(int i = 0; i < ans.size(); i++){
			printf("%d ", ans[i]);
		}
		return 0;
	}
	dfs(s);
	if(cyc){
		puts("Draw");
	}
	else puts("Lose");
	return 0;
}