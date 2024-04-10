#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

struct Node{
	int son[26];
	bool tag;
}t[maxn];

int cnt;

int ans[maxn];

int n, k;
char s[5];
int x;
int id[maxn];
int q[maxn];

int dfs(int i, int v){
	int siz = 0;
	if(t[i].tag) siz = 1, ans[i] = min(ans[i], v);
	for(int j = 0;j < 26;j++){
		if(!t[i].son[j]) continue;
		ans[t[i].son[j]] = ans[i] + 1;
		siz += dfs(t[i].son[j], min(ans[t[i].son[j]], v) + siz);
	}
	return siz;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%s", &x, s);
		if(!t[id[x]].son[s[0] - 'a']) t[id[x]].son[s[0] - 'a'] = ++cnt;
		id[i] = t[id[x]].son[s[0] - 'a'];
	}
	scanf("%d", &k);
	for(int i = 1;i <= k;i++){
		scanf("%d", &q[i]);
		t[id[q[i]]].tag = true;
	}
	//memset(ans, 0x3f, sizeof(ans));
	dfs(0, 0x3f3f3f3f);
	for(int i = 1;i <= k;i++) printf("%d ", ans[id[q[i]]]);
}