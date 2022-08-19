#include <bits/stdc++.h>
typedef long long lint;
typedef long double llf;
using namespace std;
typedef pair<int, int> pi;

int n;
int win[10000][2];
int deg[10000][2];
int vis[10000][2];
vector<int> p, q;

void Do(){
	memset(win, -1, sizeof(win));
	memset(vis, 0, sizeof(vis));
	queue<pi> que;
	que.push(pi(0, 0));
	que.push(pi(0, 1));
	vis[0][0] = vis[0][1] = 1;
	win[0][0] = win[0][1] = 0;
	for(int i=1; i<n; i++){
		deg[i][0] = p.size();
		deg[i][1] = q.size();
	}
	while(!que.empty()){
		auto x = que.front();
		que.pop();
		if(x.second == 1){
			for(auto &i : p){
				int nxt = (x.first + n - i) % n;
				deg[nxt][0]--;
				win[nxt][0] = max(win[nxt][0], 1 - win[x.first][1]);
				if(win[nxt][0]) deg[nxt][0] = 0;
				if(!vis[nxt][0] && deg[nxt][0] == 0){
					vis[nxt][0] = 1;
					que.push(pi(nxt, 0));
				}
			}
		}
		else{
			for(auto &i : q){
				int nxt = (x.first + n - i) % n;
				deg[nxt][1]--;
				win[nxt][1] = max(win[nxt][1], 1 - win[x.first][0]);
				if(win[nxt][1]) deg[nxt][1] = 0;
				if(!vis[nxt][1] && deg[nxt][1] == 0){
					vis[nxt][1] = 1;
					que.push(pi(nxt, 1));
				}
			}
		}
	}
	for(int i=1; i<n; i++){
		if(!vis[i][0]) printf("Loop ");
		else if(win[i][0] == 1) printf("Win ");
		else printf("Lose ");
	}
}

int main(){
	cin >> n;
	int k; cin >> k;
	p.resize(k); for(auto &i : p) cin >> i;
	cin >> k; q.resize(k);
	for(auto &i : q) cin >> i;
	Do();
	swap(p, q);
	puts("");
	Do();
}