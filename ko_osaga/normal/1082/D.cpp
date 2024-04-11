#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
using lint = long long;
using pi = pair<int, int>;

int n, a[MAXN];
int adj[MAXN][MAXN];

int getdiam(vector<pi> v){
	memset(adj, 0x3f, sizeof(adj));
	for(auto &i : v){
		adj[i.first][i.second] = 1;
		adj[i.second][i.first] = 1;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
	int ret = 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ret = max(ret, adj[i][j]);
	return ret;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	if(accumulate(a + 1, a + n + 1, 0) < 2 * n - 2){
		puts("NO");
		return 0;
	}
	vector<int> one, nie;
	for(int i=1; i<=n; i++){
		if(a[i] == 1) one.push_back(i);
		else nie.push_back(i);
	}
	vector<pi> ed;
	for(int i=1; i<nie.size(); i++){
		ed.emplace_back(nie[i-1], nie[i]);
		a[nie[i-1]]--;
		a[nie[i]]--;
	}
	if(!one.empty()){
		ed.emplace_back(one.back(), nie[0]);
		a[nie[0]]--;
		one.pop_back();
	}
	if(!one.empty()){
		ed.emplace_back(one.back(), nie.back());
		a[nie.back()]--;
		one.pop_back();
	}
	for(auto &i : one){
		for(auto &j : nie){
			if(a[j]){
				ed.emplace_back(i, j);
				a[j]--;
				break;
			}
		}
	}
	printf("YES %d\n", getdiam(ed));
	printf("%d\n", n - 1);
	for(auto &i : ed) printf("%d %d\n", i.first, i.second);
}