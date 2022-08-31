#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[205]; lint l;

int trie[205][26], p, fail[205], suc[205], suct[205];
int adj[205][205];

struct mat{
	lint dp[205][205];
	void init(){
		for(int i=0; i<=p; i++){
			for(int j=0; j<=p; j++){
				dp[i][j] = -1e18;
				if(i == j) dp[i][j] = 0;
			}
		}
	}
	void init2(){
		for(int i=0; i<=p; i++){
			for(int j=0; j<=p; j++){
				if(adj[i][j]) dp[i][j] = suc[j];
				else dp[i][j] = -1e18;
			}
		}
	}
	void multiply(mat &m){
		lint nxt[205][205];
 		for(int i=0; i<=p; i++){
			for(int j=0; j<=p; j++){
				nxt[i][j] = -1e18;
				for(int k=0; k<=p; k++){
					nxt[i][j] = max(nxt[i][j], dp[i][k] + m.dp[k][j]);
				}
			}
		}
		memcpy(dp, nxt, sizeof(dp));
	}
};

lint solve(lint l){
	mat piv, cur;
	piv.init();
	cur.init2();
	while(l){
		if(l&1) piv.multiply(cur);
		cur.multiply(cur);
		l >>= 1;
	}
	lint ans = 0;
	for(int i=0; i<=p; i++){
		ans = max(ans, piv.dp[0][i]);
	}
	return ans;
}

char buf[555];

int main(){
	cin >> n >> l;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		int cur = 0;
		for(int j=0; buf[j]; j++){
			if(!trie[cur][buf[j] - 'a']){
				trie[cur][buf[j] - 'a'] = ++p;
			}
			cur = trie[cur][buf[j] - 'a'];
		}
		suc[cur] += a[i];
	}
	queue<int> que;
	for(int i=0; i<26; i++){
		if(trie[0][i]) que.push(trie[0][i]);
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i=0; i<26; i++){
			if(trie[x][i]){
				int nf = fail[x];
				while(nf && !trie[nf][i]) nf = fail[nf];
				nf = trie[nf][i];
				fail[trie[x][i]] = nf;
				if(suc[nf]){
					suc[trie[x][i]] += suc[nf];
				}
				que.push(trie[x][i]);
			}
		}
	}
	for(int i=0; i<=p; i++){
		for(int j=0; j<26; j++){
			int p = i;
			while(p && !trie[p][j]) p = fail[p];
			p = trie[p][j];
			adj[i][p] = 1;
		}
	}
	cout << solve(l);
}