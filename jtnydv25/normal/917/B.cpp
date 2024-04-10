#include <bits/stdc++.h>
using namespace std;

const int N = 105;
#define F first
#define S second

int dp[N][N][N];

vector<pair<int, char>> con[N];
int indeg[N];
set<pair<int, int> > st;

vector<int> vec;
// int done[N];
bool done[N][N][N];
bool get(int i, int j, int k){
	if(done[i][j][k]) return dp[i][j][k];
	for(auto it : con[i]){
		if(it.S - 'a' >= k){
			if(!get(j, it.F, it.S - 'a')) dp[i][j][k] = 1;
		}
	}
	done[i][j][k] = 1;
	return dp[i][j][k];
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		char c;
		cin >> u >> v >> c;
		con[u].push_back({v, c});
		indeg[v]++;
	}
	/*for(int i = 1; i <= n; i++) st.insert({indeg[i], i});
	while(!st.empty()){
		int v = (st.begin()->S);
		done[v] = 1;
		st.erase(st.begin());
		for(auto it2 : con[v]){
			int u = it2.F;
			if(done[u]) continue;
			st.erase({indeg[u], u});
			indeg[u] --;
			st.insert({indeg[u], u})
		}
	}

	for(int k = 25; k >= 0; k--){
		for(int indi = 0; indi < n; indi++){
			for(int indj = 0; indj < n; indj++){
				int i = vec[indi], j = vec[indj];
				for(auto it : con[i]){
					if(it.S - 'a' >= k && !dp[1][it.S - 'a'][it.F][j]) dp[k][i][j] = 1;
				}
			}
		}
	}*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			if(get(i, j, 0)) cout << 'A';
			else cout << 'B';
		}
		cout << endl;
	}
}