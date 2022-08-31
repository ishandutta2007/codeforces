#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

int n;
vector<pi> gph[300005];

struct trie{
	trie *nxt[26];
	int sz;
	trie(){
		sz = 0;
		for(int i=0; i<26; i++) nxt[i]= NULL;
	};
}*node[300005];

int cnt[300005], dep[300005];
int ans[300005];

void dfs2(int x, trie *n){
	for(auto &i : gph[x]){
		if(!n->nxt[i.first-'a']){
			n->nxt[i.first-'a'] = new trie();
		}
		dfs2(i.second, n->nxt[i.first-'a']);
	}
	n->sz = 0;
	for(int i=0; i<26; i++){
		if(n->nxt[i]) n->sz += n->nxt[i]->sz + 1;
	}
}

int compute(trie *a, trie *b){
	int ret = 0;
	for(int i=0; i<26; i++){
		if(a->nxt[i] && b->nxt[i]) ret += compute(a->nxt[i], b->nxt[i]) + 1;
		else if(a->nxt[i]) ret += a->nxt[i]->sz + 1;
		else if(b->nxt[i]) ret += b->nxt[i]->sz + 1;
	}
	return ret;
}


void dfs(int x, int p, int d){
	cnt[d]++;
	dep[x] = d;
	sort(gph[x].begin(), gph[x].end());
	node[x] = new trie();
	int mxp = -1, pos = -1;
	for(auto &i : gph[x]){
		gph[i.second].erase(find(gph[i.second].begin(),gph[i.second].end(),pi(i.first, x)));
		dfs(i.second, x, d+1);
		if(mxp < node[i.second]->sz){
			mxp = node[i.second]->sz;
			pos = i.second;
		}
		node[x]->sz += node[i.second]->sz + 1;
		node[x]->nxt[i.first-'a'] = node[i.second];
	}
	if(pos == -1) return;
	trie *nn = new trie();
	for(auto &i : gph[x]){
		if(pos != i.second) dfs2(i.second, nn);
	}
	ans[d+1] += compute(nn, node[pos]);
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e;
		char x[5];
		scanf("%d %d %s",&s,&e,x);
		gph[s].push_back(pi(x[0], e));
		gph[e].push_back(pi(x[0], s));
	}
	dfs(1, 0, 0);
	cnt[0] = 0;
	for(int i=1; i<=n; i++) cnt[i] += cnt[i-1];
	int ans = 1e9, pos = -1;
	for(int i=1; i<=n; i++){
		int w = ::ans[i] + cnt[i-1];
		if(w < ans){
			ans = w;
			pos = i;
		}
	}
	cout << ans + 1 << endl << pos;
}