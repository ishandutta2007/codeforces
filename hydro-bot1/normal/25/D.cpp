// Hydro submission #62234a7be56236d5e8473860@1646479996041
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f


using namespace std;

typedef long long ll;

const int N = 10100, MAXN = 200100;
queue<int> maps[1100];
typedef pair<ll, ll> PLL;

int fa[200100];
int vis[200100];
vector<pair<ll, ll>> edge;


int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void slove() {
	int n; cin >> n;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		int x = find(u), y = find(v);
		if(x == y) {
			edge.push_back({u, v});
		} else {
			fa[x] = y;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(fa[i] == i){
			q.push(i);
		}
	}
	int k = edge.size(), cnt = 1;
	cout << k << '\n';
	while(cnt <= k){
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		cout << edge[cnt - 1].first << " " << edge[cnt - 1].second << ' ' << a << ' ' << b << '\n';
		q.push(a);
		cnt++;
	}
}




int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    slove();
    
}