#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

const int MAXN = 1000005, MAXC = 26;
vector<int> gph[1000005];

int trie[MAXN][MAXC], fail[MAXN], term[MAXN], piv;
vector<int> init(vector<string> &v){
	vector<int> ret;
	int idx = 0;
	for(auto &i : v){
		int p = 0;
		for(auto j : i){
			j -= 'a';
			if(!trie[p][j]) trie[p][j] = ++piv;
			p = trie[p][j];
		}
		ret.push_back(p);
		term[p] = ret.size();
	}
	queue<int> que;
	for(int i=0; i<MAXC; i++){
		if(trie[0][i]) que.push(trie[0][i]);
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i=0; i<MAXC; i++){
			if(trie[x][i]){
				int p = fail[x];
				while(p && !trie[p][i]) p = fail[p];
				p = trie[p][i];
				fail[trie[x][i]] = p;
				que.push(trie[x][i]);
			}
		}
	}
	for(int i=1; i<=piv; i++){
		gph[fail[i]].push_back(i);
	}
	return ret;
}

int n, q, k;
char str[1000005];
int chk[1000005];
int dfn[1000005], sz[1000005], p2;

void dfs(int x){
	dfn[x] = ++p2;
	sz[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
		sz[x] += sz[i];
	}
}

struct bit{
	int tree[1000005];
	void add(int x, int v){
		while(x <= p2){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int chk2[1000005];

int main(){
	scanf("%d %d",&q,&k);
	vector<string> v;
	for(int i=1; i<=k; i++){
		scanf("%s", str);
		v.push_back(str);
		chk2[i] = 1;
	}
	auto ans = init(v);
	dfs(0);
	for(auto &i : ans){
		bit.add(dfn[i], 1);
		bit.add(dfn[i] + sz[i], -1);
	}
	n = piv;
	while(q--){
		scanf("%s", str);
		if(*str == '+'){
			int x;
			sscanf(str + 1, "%d", &x);
			if(chk2[x] == 1) continue;
			chk2[x] = 1;
			x = ans[x-1];
			bit.add(dfn[x], 1);
			bit.add(dfn[x] + sz[x], -1);
		}
		if(*str == '-'){
			int x;
			sscanf(str + 1, "%d", &x);
			if(chk2[x] == 0) continue;
			chk2[x] = 0;
			x = ans[x-1];
			bit.add(dfn[x], -1);
			bit.add(dfn[x] + sz[x], 1);
		}
		if(*str == '?'){
			int p = 0;
			lint ans = 0;
			for(int j=1; str[j]; j++){
				while(p && !trie[p][str[j] - 'a']){
					p = fail[p];
				}
				p = trie[p][str[j] - 'a'];
				ans += bit.query(dfn[p]);
			}
			printf("%lld\n", ans);
		}
	}
}