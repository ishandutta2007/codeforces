#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int to, next;
}v[1000086];

int n, m;
int tot = 0, head[500086];
int depth[500086], f[500001][22], lg[500001];//log2(i) 

int read(){
    int re=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ 
        re=re*10+ch-'0'; 
        ch=getchar();
    }
    return re;
}

void add(int x, int y){
    v[++tot].to = y;
    v[tot].next = head[x];
    head[x] = tot;
}

void dfs(int i, int fa){
    depth[i] = depth[fa] + 1;
    f[i][0] = fa;
    for(int j = 1;(1 << j) <= depth[i];j++){
        f[i][j] = f[f[i][j-1]][j-1];
    }
    for(int j = head[i];j != 0;j = v[j].next){
        if(v[j].to != fa) dfs(v[j].to, i);
    }
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    while(depth[x] > depth[y]) x = f[x][lg[depth[x] - depth[y]]];
    if(x == y) return y;
    for(int i = lg[depth[x]];i >= 0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i < n;i++){
        int a, b;
        a = read();
        b = read();
        add(a, b);
        add(b, a);
    }
    for(int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
    dfs(1, 0); 
    int k, x, y;
    while(m--){
    	k = read();
    	bool suc = true;
    	y = 0; 
    	while(k--){
    		x = read();
    		if(!suc) continue;
    		x = f[x][0];
    		if(!y) y = x;
    		else{
    			int z = lca(x, y);
    			if(z != x && z != y) suc = false;
    			else y = z == y ? x : y;
			}
		}
		puts(suc ? "YES" : "NO");
	}
}