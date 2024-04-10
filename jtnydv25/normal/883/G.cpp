#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

const int N = 3e5 + 10;

vi con[N], con2[N];
int a[N], b[N], t[N];
vector<int> edgeind[N];
int orientation[N];
int vis[N];
int n, m;
void bfsmax(int s){
	queue<int> q;
	q.push(s);
	memset(vis, 0, sizeof vis);
	memset(orientation, 0, sizeof orientation);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i : edgeind[u]){
			int v = a[i] ^ b[i] ^ u;
			if(vis[v]) continue;
			if(t[i] == 1){
				q.push(v);
				vis[v] = 1;
				continue;
			}

			if(orientation[i] == 1 && a[i] == u){
				q.push(v);
				vis[v] = 1;
			}

			else if(orientation[i] == 2 && a[i] == v){
				q.push(v);
				vis[v] = 1;
			}

			else if(orientation[i] == 0){
				orientation[i] = (a[i] == u) ? 1 : 2;
				q.push(v);
				vis[v] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(vis[i]) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++){
		if(t[i] == 2){
			printf("%c", (orientation[i] == 1 ? '+' : '-'));
		}
	}
	printf("\n");
}

void bfsmin(int s){
	queue<int> q;
	q.push(s);
	memset(vis, 0, sizeof vis);
	memset(orientation, 0, sizeof orientation);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : edgeind[u]){
			int v = a[i] ^ b[i] ^ u;
			if(vis[v]) continue;
			if(t[i] == 1){
				q.push(v);
				vis[v] = 1;
				continue;
			}

			if(orientation[i] == 1 && a[i] == u){
				q.push(v);
				vis[v] = 1;
			}

			else if(orientation[i] == 2 && a[i] == v){
				q.push(v);
				vis[v] = 1;
			}

			else if(orientation[i] == 0){
				orientation[i] = (a[i] == u) ? 2 : 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(vis[i]) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++){
		if(t[i] == 2)
			printf("%c", (orientation[i] == 1 ? '+' : '-'));
	}
}

int main(){
	int s;
	sd(n); sd(m); sd(s);
	for(int i = 1; i <= m; i++){
		sd(t[i]); sd(a[i]); sd(b[i]);
		edgeind[a[i]].pb(i);
		if(t[i] == 2){
			edgeind[b[i]].pb(i);
		}
	}
	bfsmax(s);
	bfsmin(s);
}