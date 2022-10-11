#include <bits/stdc++.h>
using namespace std;

#define pb push_back


int color[10100];
vector< int > a[10100];
int n, p;


int dfs(int u, int c){
	int ans = 0;
	if(c != color[u]){
		c = color[u];
		ans++;
	}
	for(int i = 0; i < a[u].size(); i++){
		ans += dfs(a[u][i], c);
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> p;
		a[p].pb(i);
	}
	for(int i = 1; i <= n; i++){
		cin >> p;
		color[i] = p;
	}
	cout << dfs(1, 0);
	return 0;
}