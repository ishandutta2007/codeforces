#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
using lint = long long;
using pi = pair<lint, lint>;

int n, k;
int trie[MAXN][10], cnt[MAXN], piv, dep[MAXN];
int dp[MAXN][MAXN][12];

int f(int pos, int d, int k){
	if(~dp[pos][d][k]) return dp[pos][d][k];
	int ret = 1e9;
	vector<int> aux(k + 1, 0);
	for(int i=0; i<10; i++){
		if(trie[pos][i]){
			vector<int> tmp;
			for(int j=0; j<=k; j++) tmp.push_back(f(trie[pos][i], d, j));
			vector<int> nxt(k + 1, 1e9);
			for(int i=0; i<=k; i++) for(int j=0; i+j<=k; j++) nxt[i + j] = min(nxt[i + j], tmp[j] + aux[i]);
			aux = nxt;
		}
	}
	ret = min(ret, aux[k]);
	ret += cnt[pos] * (dep[pos] - d);
	if(k > 0) ret = min(ret, f(pos, dep[pos], k - 1));
	return dp[pos][d][k] = ret;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		string s; int c;
		cin >> s >> c;
		int p = 0;
		for(auto &j : s){
			if(!trie[p][j-'0']){
				trie[p][j-'0'] = ++piv;
				dep[piv] = dep[p] + 1;
			}
			p = trie[p][j-'0'];
		}
		cnt[p] += c;
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, k) << endl;
}