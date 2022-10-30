#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t;
int n, m;
char s[maxn][maxn];
int sk[maxn], top;
bool ins[maxn], vis[maxn];
int f[maxn], g[maxn];
vector<int> v;
bool tag;

void dfs(int i){
	if(vis[i] || tag) return;
	vis[i] = true, sk[++top] = i, ins[i] = true;
	for(int j = 1;j <= n;j++){
		if(s[i][j] == 'a'){
			dfs(j);
			if(tag) return;
			if(ins[j]){
				while(1){
					int x = sk[top--];
					v.push_back(x);
					if(x == j) break;
				}
				tag = true;
				return;
			}
			if(f[j] + 1 > f[i]) f[i] = f[j] + 1, g[i] = j;
		}
	}
	ins[i] = false;
	top--;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		int x = 0, y = 0, z;
		for(int i = 1;i <= n && !x;i++){
			for(int j = i + 1;j <= n && !x;j++){
				if(s[i][j] == s[j][i]){
					x = i, y = j;
				}
			}
		}
		if(!x && (m & 1)){
			x = 1, y = 2;
		}
		if(x){
			puts("YES");
			for(int i = 1;i <= m + 1;i++) printf("%d ", i & 1 ? x : y);
			puts("");
			continue;
		}
		v.clear(), top = tag = 0;
		for(int i = 1;i <= n;i++) f[i] = g[i] = ins[i] = vis[i] = 0;
		x = 0;
		for(int i = 1;i <= n;i++){
			dfs(i);
			if(f[i] > f[x]) x = i;
		}
		if(tag){
			puts("YES");
			for(int i = 1;i <= m + 1;i++) printf("%d ", v[i % v.size()]);
			puts("");
		}else{
			if(f[x] == 1){
				puts("NO");
				continue;
			}
			puts("YES");
			y = g[x], z = g[y];
			v.push_back(x), v.push_back(y), v.push_back(z);
			for(int i = 0;i < m + 5;i++){
				int x = v[v.size() - 2], y = v[v.size() - 3];
				v.push_back(x), v.push_back(y);
			}
			if(m % 4 == 2){
				for(int i = 0;i < m + 1;i++) printf("%d ", v[i]);
			}else{
				for(int i = 1;i <= m + 1;i++) printf("%d ", v[i]);
			}
			puts("");
		}
	}
}
/*
1
3 4
*aa
b*a
bb*
*/