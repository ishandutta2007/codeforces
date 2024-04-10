#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

typedef long long ll;

struct Node{
	int len, link;
	int edge[2];
}t[maxn];

int cnt, last;

void init(){
	t[1].len = 0;
	t[1].link = 0;
	last = 1;
	cnt = 1;
}

void insert(char c){
	int x = c - '0';
	int cur = ++cnt;
	t[cur].len = t[last].len + 1;
	int p = last;
	for(;p && !t[p].edge[x];p = t[p].link) t[p].edge[x] = cur;
	if(!p){
		t[cur].link = 1;
	}else{
		int q = t[p].edge[x];
		if(t[q].len == t[p].len + 1){
			t[cur].link = q;
		}else{
			int clone = ++cnt;
			t[clone].len = t[p].len + 1;
			memcpy(t[clone].edge, t[q].edge, sizeof(t[q].edge));
			for(;p && t[p].edge[x] == q;p = t[p].link) t[p].edge[x] = clone;
			t[clone].link = t[q].link;
			t[q].link = t[cur].link = clone;
		}
	}
	last = cur;
}



int T; 
char s[maxn];
char S[maxn];
int n, k;

bool vis[maxn];
int f[maxn];


void dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	f[i] = 1e9;
	for(int j = 0;j <= 1;j++){
		int to = t[i].edge[j];
		dfs(to);
		f[i] = min(f[i], f[to]);
	}
	if(f[i] == 1e9) f[i] = 0;
	if(t[i].edge[0] && t[i].edge[1]) f[i]++;
	else f[i] = 0;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%s", &n, &k, s + 1);
		for(int i = 1;i <= k;i++) S[i] = '0';
		S[k + 1] = 0;
		init();
		for(int i = 1;i <= n;i++) insert(s[i] == '1' ? '0' : '1');
		dfs(1);
		int now = 1;
		bool tag = false;
		for(int i = 1;i <= k;i++){
			if(!t[now].edge[0]) break;
			if(i + f[t[now].edge[0]] < k){
				now = t[now].edge[0];
				S[i] = '0';
				continue;
			}
			if(t[now].edge[1] && i + f[t[now].edge[1]] < k){
				now = t[now].edge[1];
				S[i] = '1';
				continue;
			}
			if(!t[now].edge[1]){
				S[i] = '1';
				break;
			}
			tag = true;
			puts("NO");
			break; 
		}
		if(!tag){
			printf("YES\n%s\n", S + 1);
		} 
		for(int i = 1;i <= cnt;i++) t[i].len = t[i].link = t[i].edge[0] = t[i].edge[1] = vis[i] = f[i] = 0;
	} 
}