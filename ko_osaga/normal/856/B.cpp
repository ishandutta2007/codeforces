#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 1e9 + 7;
const int MAXN = 1000005, MAXC = 26;
int trie[MAXN][MAXC], fail[MAXN], term[MAXN], piv;
int len[MAXN];

vector<int> gph[MAXN];
int dp[MAXN][2], vis[MAXN];

void dfs(int x, int p){
	vis[x] = 1;
	dp[x][1]++;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		dp[x][0] += max(dp[i][0], dp[i][1]);
		dp[x][1] += dp[i][0];
	}
}

void solve(){
	for(int i=0; i<=piv; i++){
		memset(dp[i], 0, sizeof(dp[i]));
		gph[i].clear();
		vis[i] = 0;
	}
	for(int i=1; i<=piv; i++){
		if(fail[i] && len[fail[i]] + 1 == len[i]){
			gph[fail[i]].push_back(i);
			gph[i].push_back(fail[i]);
		}
	}
	int ans = 0;
	for(int i=1; i<=piv; i++){
		if(!vis[i]){
			dfs(i, 0);
			ans += max(dp[i][0], dp[i][1]);
		}
	}
	printf("%d\n", ans);
}

void init(vector<string> &v){
	for(int i=0; i<=piv; i++){
		memset(trie[i], 0, sizeof(trie[i]));
		term[i] = fail[i] = 0;
	}
	piv = 0;
	for(auto &i : v){
		int p = 0;
		int cnt = 0;
		for(auto &j : i){
			if(!trie[p][j]) trie[p][j] = ++piv;
			p = trie[p][j];
			len[p] = ++cnt;
		}
		term[p] = 1;
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
				if(term[p]) term[trie[x][i]] = 1;
				que.push(trie[x][i]);
			}
		}
	}
}

char buf[1000005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		vector<string> s;
		int n; scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%s", buf);
			s.push_back(buf);
		}
		for(auto &i : s){
			for(auto &j : i) j -= 'a';
		}
		init(s);
		solve();
	}
}