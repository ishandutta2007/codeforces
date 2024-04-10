#include<bits/stdc++.h>
using namespace std;

const int __ = 1e7 + 7 , _ = 1e6 + 7;
struct Edge{int end , upEd , f , c;}Ed[__];
int head[_] , cur[_] , cntEd = 1 , dis[_] , val[103] , N , M , S , T;
void addEd(int a  , int b , int f , int c){Ed[++cntEd] = (Edge){b , head[a] , f , c}; head[a] = cntEd;}
void addE(int a , int b , int f , int c = 0){addEd(a , b , f , c); addEd(b , a , 0 , -c);}

bool vis[_]; queue < int > q;
bool SPFA(){
	memset(dis , 0x3f , sizeof(int) * (T + 2)); while(!q.empty()) q.pop();
	dis[S] = 0; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop(); vis[t] = 0;
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dis[Ed[i].end] > dis[t] + Ed[i].c){
				dis[Ed[i].end] = dis[t] + Ed[i].c;
				if(!vis[Ed[i].end]){vis[Ed[i].end] = 1; q.push(Ed[i].end);}
			}
	}
	memcpy(cur , head , sizeof(int) * (T + 1)); return dis[T] != dis[T + 1];
}

int dfs(int x , int mn){
	if(x == T) return mn;
	int sum = 0; vis[x] = 1;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end] && Ed[i].f && dis[Ed[i].end] == dis[x] + Ed[i].c){
			int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f));
			sum += t; Ed[i].f -= t; Ed[i ^ 1].f += t;
			if(sum == mn) break;
		}
	vis[x] = 0; return sum;
}

int Dinic(){int sum = 0; while(SPFA()) sum += dfs(S , 2e9) * dis[T]; return sum;}

int main(){
	cin >> N >> M; --N; int sum = 0; T = N + M + 1;
	for(int i = 1 ; i <= M ; ++i){
		int u , v , f , c; cin >> u >> v >> f >> c; sum += max(0 , c - f); if(v > N) v = 1;
		val[v] += c; val[u] -= c; addE(N + i , v , 1e8); addE(v , N + i , 1e8); addE(u , N + i , 1e8 , 2);
		if(f <= c){addE(N + i , u , c - f); addE(N + i , u , f , 1);} else{addE(N + i , u , c , 1); addE(u , N + i , f - c , 1);}
	}
	for(int i = 1 ; i <= N ; ++i) if(val[i] < 0) addE(i , T , -val[i]); else addE(S , i , val[i]);
	cout << Dinic() + sum << endl; return 0;
}