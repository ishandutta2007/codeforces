#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define L first
#define R second
#define MP make_pair
#define PB push_back

const int maxn = 1e6 + 100;
int par[maxn], dp[maxn], next[maxn];
vector<int> v[maxn];

void dfs(int x){
	dp[x] = 1;
	for(int i=0;i<v[x].size();i++){
		int child = v[x][i];
		par[child] = x;
		dfs(child);
		dp[x] += dp[child];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int match = 0, root = s.size();
	next[0] = 0;
	v[root].PB(0);
	for(int i=1;i<s.size();i++){
		while(match != 0 and s[match] != s[i])
			match = next[match - 1];
		if(s[match] == s[i])
			match++;
		next[i] = match;
		if(match != 0)
			v[match - 1].PB(i);
		else
			v[root].PB(i);
	}
	dfs(root);
	int cur = s.size() - 1;
	while(cur != root){
		if(dp[cur] >= 3){
			cout << s.substr(0, cur + 1) << endl;
			return 0;
		}
		cur = par[cur];
	}
	cout << "Just a legend" << endl;
}