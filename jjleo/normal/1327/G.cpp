#include <bits/stdc++.h>
#define maxn 400086
#define maxm 1086

using namespace std;

struct Node{
	int edge[14];
	int fail;
	int val;
}trie[maxn];

typedef long long ll;

int cnt;
queue<int> q;
//int sa[maxn], tot;

void add(char *s, int val){
	int len = strlen(s);
	int now = 0;
	for(int i = 0;i < len;i++){
		if(!trie[now].edge[s[i] - 'a']){
			cnt++;
			trie[now].edge[s[i] - 'a'] = cnt;
		}
		now = trie[now].edge[s[i] - 'a'];//if  
	}
	trie[now].val += val;
}

void build(){
	for(int i = 0;i < 14;i++){
		if(trie[0].edge[i]){
			q.push(trie[0].edge[i]);
		}
	}// 
	while(!q.empty()){
		int u = q.front();
		//sa[++tot] = u;
		q.pop();
		for(int i = 0;i < 14;i++){
			if(trie[u].edge[i]){
				int v = trie[u].edge[i];
				trie[v].fail = trie[trie[u].fail].edge[i];
				trie[v].val += trie[trie[v].fail].val;
				q.push(trie[u].edge[i]);
			}else{
				trie[u].edge[i] = trie[trie[u].fail].edge[i];
			}
		}
	}
}

int n, len, x;
char s[maxn];
ll f[maxm][1 << 14], g[maxm][1 << 14];
int to[15][maxm];
ll val[15][maxm];
int m;// 
ll ans = -1e18;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%s%d", s, &x);
		add(s, x);
	}
	build();
	//for(int i = 1;i <= tot;i++) trie[sa[i]].val += trie[trie[sa[i]].fail].val;
	scanf("%s", s + 1);
	len = strlen(s + 1);
	for(int i = 0;i < 15;i++) for(int j = 0;j <= cnt;j++) to[i][j] = j;
	for(int i = 1;i <= len;i++){
		if(s[i] == '?'){
			m++;
			continue;
		}
		for(int j = 0;j <= cnt;j++){
			to[m][j] = trie[to[m][j]].edge[s[i] - 'a'];
			val[m][j] += trie[to[m][j]].val;
		}
	}
	//for(int i = 0;i <= m;i++) for(int j = 0;j <= cnt;j++) printf("%d %d %lld--\n", i, j, val[i][j]);
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 0;i <= m;i++){
		memset(g, -0x3f, sizeof(g));
		for(int j = 0;j <= cnt;j++){
			for(int k = (1 << 14) - 1;k >= 0;k--){
				g[to[i][j]][k] = max(g[to[i][j]][k], f[j][k] + val[i][j]);
			}
		}
		for(int j = 0;j <= cnt;j++){
			for(int k = (1 << 14) - 1;k >= 0;k--){
				f[j][k] = g[j][k];
				//if(f[j][k] >= -100) printf("%d %d %lld--\n", j, k, f[j][k]);
			}
		}
		if(i == m) break;//debug: = = 
		memset(g, -0x3f, sizeof(g));
		for(int j = 0;j <= cnt;j++){
			for(int k = (1 << 14) - 2;k >= 0;k--){//  
				if(f[j][k] <= -1e15) continue;//debug:ac 
				for(int l = 1 << 13, p = 13;l;l >>= 1, p--){
					if(k & l) continue;
					g[trie[j].edge[p]][k | l] = max(g[trie[j].edge[p]][k | l], f[j][k] + trie[trie[j].edge[p]].val);
				}
			}
		}
		for(int j = 0;j <= cnt;j++){
			for(int k = (1 << 14) - 1;k >= 0;k--){
				f[j][k] = g[j][k];
				//if(f[j][k] == 6) printf("%d %d %lld--\n", j, k, f[j][k]);
			}
		}
	}
	for(int i = 0;i <= cnt;i++){
		for(int j = (1 << 14) - 1;j >= 0;j--){
			ans = max(ans, f[i][j]);
		}
	}
	printf("%lld", ans);
}