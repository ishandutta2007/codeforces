#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))

const int N = 100005;
const int logN = 20;

vector<pair<int, int> > con[N];
int par[logN][N],depth[N], sm[N], root[N];
int st[N], en[N], T, comp[N], cmp;
void dfs(int s, int d, int p){
	st[s] = ++T;
	comp[s] = cmp;
    depth[s] = d;
    par[0][s] = p;
    for(auto it:con[s]){
    	int v = it.first;
        if(v!=p){
        	sm[v] = sm[s] + it.second;
            dfs(v,d+1,s);
        }
    }
    en[s] = T;
}

void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            par[j][i] = par[j-1][par[j-1][i]];
}

int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}

int main(){
	int n, p, t;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p);
		sd(t);
		if(t == -1){
			root[i] = 1;
		}
		else{
			int u = i, v = p;
			con[u].push_back({v, t});
			con[v].push_back({u, t});
		}
	}

	for(int i = 1; i <= n; i++)
		if(root[i]){
			cmp++;
			dfs(i, 0, 0);
		}

	pre(n);

	int q;
	sd(q);
	while(q--){
		int u, v, t;
		sd(t); sd(u); sd(v);
		if(u == v || comp[u] != comp[v]){
			printf("NO\n");
			continue;
		}
		int l = lca(u, v);
		if(t == 1){
			if(l == u && sm[v] - sm[u] == 0){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			if(v == l){
				printf("NO\n");
				continue;
			}
			int sm1 = sm[u] - sm[l], sm2 = sm[v] - sm[l];
			if(sm1 == 0 && sm2 == depth[v] - depth[l]){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
}