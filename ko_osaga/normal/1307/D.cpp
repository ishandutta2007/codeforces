#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 300005;

vector<int> gph[MAXN];
int dist[2][MAXN];

void bfs(int x, int *dist){
	dist[x] = 0;
	queue<int> que;
	que.push(x);
	while(sz(que)){
		int x = que.front(); que.pop();
		for(auto &j : gph[x]){
			if(dist[j] > dist[x] + 1){
				que.push(j);
				dist[j] = dist[x] + 1;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int m, k; scanf("%d %d",&m,&k);
	vector<int> v(k);
	for(auto &i : v){
		scanf("%d",&i);
	}
	for(int i=1; i<=m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	memset(dist, 0x3f, sizeof(dist));
	bfs(1, dist[0]);
	bfs(n, dist[1]);
	sort(all(v), [&](const int &a, const int &b){
		return dist[0][a] - dist[1][a] < dist[0][b] - dist[1][b];
	});
	int cur = -1e9;
	int ret = -1e9;
	for(int i=0; i<sz(v); i++){
		ret = max(ret, 1 + dist[1][v[i]] + cur);
		cur = max(cur, dist[0][v[i]]);
	}
	cout << min(dist[1][1], ret) << endl;
}