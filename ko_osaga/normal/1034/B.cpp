#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;

const int MAXN = 50005, MAXM = 50005;
vector<int> gph[MAXN];
int dis[MAXN], l[MAXN], r[MAXM], vis[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear();	}
void add_edge(int l, int r){ gph[l].push_back(r); }
bool bfs(int n){
	queue<int> que;
	bool ok = 0;
	memset(dis, 0, sizeof(dis));
	for(int i=0; i<n; i++){
		if(l[i] == -1 && !dis[i]){
			que.push(i);
			dis[i] = 1;
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &i : gph[x]){
			if(r[i] == -1) ok = 1;
			else if(!dis[r[i]]){
				dis[r[i]] = dis[x] + 1;
				que.push(r[i]);
			}
		}
	}
	return ok;
}
bool dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(r[i] == -1 || (!vis[r[i]] && dis[r[i]] == dis[x] + 1 && dfs(r[i]))){
			l[x] = i; r[i] = x;
			return 1;
		}
	}
	return 0;
}
int match(int n){
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int ret = 0;
	while(bfs(n)){
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) if(l[i] == -1 && dfs(i)) ret++;
	}
	return ret;
} 
bool chk[MAXN + MAXM];
void rdfs(int x, int n){
	if(chk[x]) return;
	chk[x] = 1;
	for(auto &i : gph[x]){
		chk[i + n] = 1;
		rdfs(r[i], n);
	}
}
vector<int> getcover(int n, int m){ // solve min. vertex cover
	match(n);
	memset(chk, 0, sizeof(chk));
	for(int i=0; i<n; i++) if(l[i] == -1) rdfs(i, n);
	vector<int> v;
	for(int i=0; i<n; i++) if(!chk[i]) v.push_back(i);
	for(int i=n; i<n+m; i++) if(chk[i]) v.push_back(i);
	return v;
}

int solve(int n, int m){
	clear();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((i + j) % 2 == 0){
				for(int k=-3; k<=3; k++){
					for(int l=-3; l<=3; l++){
						if(abs(k) + abs(l) != 3) continue;
						if(i + k < 0 || j + l < 0 || i + k >= n || j + l >= m) continue;
						int cur = i * m + j;
						int nxt = (i + k) * m + (j + l);
						add_edge(cur, nxt);
					}
				}
			}
		}
	}
	int ans = match(n * m) * 2;
	return ans;
}

lint solve2(lint n, lint m){
	if(n > m) swap(n, m);
	if(n == 1){
		m -= 4;
		if(m < 0) return 0;
		lint tmp = m / 6;
		lint ans = 0;
		if(m % 6 == 0) ans += 1;
		else if(m % 6 == 1) ans += 2;
		else ans += 3;
		ans += (m / 6) * 3;
		return ans * 2;
	}
	if(n == 2){
		if(m <= 2) return 0;
		if(m == 3) return 4;
		if(m == 4) return 8;
		if(m == 5) return 10;
		if(m == 6) return 12;
		if(m == 7) return 12;
		return m * 2;
	}
	if(n % 2 == 0) return n * m;
	else return ((n * m ) / 2) * 2;
}


int main(){
	int n, m; cin >> n >> m;
	cout << solve2(n, m) << endl;
}