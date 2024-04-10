#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int edge[10];
	int fail;
	bool tag;
}trie[maxn];

int cnt;
queue<int> q;

void add(int *s, int len){
	int now = 0;
	for(int i = 0;i < len;i++){
		if(!trie[now].edge[s[i]]){
			cnt++;
			trie[now].edge[s[i]] = cnt;
		}
		now = trie[now].edge[s[i]];//if  
	}
	trie[now].tag = true;
}

void build(){
	for(int i = 1;i < 10;i++){
		if(trie[0].edge[i]){
			q.push(trie[0].edge[i]);
		}
	}// 
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1;i < 10;i++){
			if(trie[u].edge[i]){
				int v = trie[u].edge[i];
				trie[v].fail = trie[trie[u].fail].edge[i];
				trie[v].tag |= trie[trie[v].fail].tag;
				q.push(trie[u].edge[i]);
			}else{
				trie[u].edge[i] = trie[trie[u].fail].edge[i];
			}
		}
	}
}


char s[maxn];
int n, x;

int a[maxn], sum, len;

void dfs(){
	if(sum == x){
		bool tag = false;
		for(int i = 1;i <= len;i++){
			int val = 0;
			for(int j = i;j <= len;j++){
				if(i == 1 && j == len) continue;
				val += a[j];
				if(x % val == 0){
					tag = true;
					break;
				}
			}
			if(tag) break;
		}
		if(!tag) add(a + 1, len);
		return;
	} 
	if(sum > x) return;
	for(int i = 1;i <= 9;i++){
		a[++len] = i, sum += i, dfs();
		--len, sum -= i;
	}
}

int f[2][maxn];

int main(){
	scanf("%s%d", s + 1, &x);
	dfs(), build();
	int len = strlen(s + 1);
	for(int i = 1;i <= cnt;i++) f[0][i] = 1e9;
	for(int i = 1;i <= len;i++){
		for(int j = 0;j <= cnt;j++) f[i & 1][j] = 1e9;
		for(int j = 0;j <= cnt;j++){
			int to = trie[j].edge[s[i] - '0'];
			if(!trie[to].tag) f[i & 1][to] = min(f[i & 1][to], f[i & 1 ^ 1][j]);
			f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][j] + 1);
		}
	}
	int ans = 1e9;
	for(int i = 0;i <= cnt;i++) ans = min(ans, f[len & 1][i]);
	printf("%d", ans);
}