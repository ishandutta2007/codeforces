#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
const int MAXN = 400005;
const int MAXC = 26;
const int mod = 998244353;
using lint = long long;
using pi = pair<int, int>;

int trie[MAXN][MAXC], fail[MAXN], term[MAXN], nxt[MAXN][MAXC], piv;

int n, q;
vector<pi> gph[MAXN], ans[MAXN];
vector<int> ftree[MAXN];
string str[MAXN];
int pos[MAXN], par[MAXN];
char buf[MAXN];
int ret[MAXN];

int aho_pos[MAXN];

void dfs(int x){
	for(auto &i : gph[x]){
		int y = nxt[aho_pos[x]][i.first - 'a'];
		aho_pos[i.second] = y;
		dfs(i.second);
	}
}

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x < MAXN){
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

int din[MAXN], dout[MAXN], ord;

void dfs3(int x){
	if(x > 0){
		bit.add(din[aho_pos[x]], +1);
	}
	for(auto &i : ans[x]){
		ret[i.second] = bit.query(dout[i.first]) - bit.query(din[i.first] - 1);
	}
	for(auto &i : gph[x]) dfs3(i.second);
	if(x > 0){
		bit.add(din[aho_pos[x]], -1);
	}
}

int func[26];

void dfsf(int x){
	din[x] = ++ord;
	vector<int> backup(func, func + 26);
	for(int i=0; i<26; i++){
		if(trie[x][i]) func[i] = trie[x][i];
		nxt[x][i] = func[i];
	}
	for(auto &i : ftree[x]){
		dfsf(i);
	}
	dout[x] = ord;
	for(int i=0; i<26; i++) func[i] = backup[i];
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		int p = 0;
		if(t == 2) scanf("%d",&p);
		scanf("%s", buf);
		par[i] = p;
		gph[p].emplace_back(*buf, i);
	}
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		scanf("%d %s",&pos[i],buf);
		str[i] = buf;
		int p = 0;
		for(auto j : str[i]){
			j -= 'a';
			if(!trie[p][j]) trie[p][j] = ++piv;
			p = trie[p][j];
		}
		term[i] = p;
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
		ftree[fail[i]].push_back(i);
	}
	dfsf(0);
	dfs(0);
	for(int i=1; i<=q; i++){
		ans[pos[i]].emplace_back(term[i], i);
	}
	dfs3(0);
	for(int i=1; i<=q; i++){
		printf("%d\n", ret[i]);
	}
}