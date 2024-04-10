#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , __ = 1e6 + 7;
struct Edge{int end , upEd , f , c;}Ed[__];
int head[_] , cntEd = 1 , dis[_] , d[_] , S , T; char col[_];
void addEd(int a , int b , int c , int d){Ed[++cntEd] = (Edge){b , head[a] , c , d}; head[a] = cntEd;}
void addE(int a , int b , int c , int d = 0){addEd(a , b , c , d); addEd(b , a , 0 , -d);}

queue < int > q; bool vis[_];
bool SPFA(){
	q.push(S); memset(dis , 0x3f , sizeof(int) * (T + 1)); dis[S] = 0;
	while(!q.empty()){
		int t = q.front(); q.pop(); vis[t] = 0;
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dis[Ed[i].end] > dis[t] + Ed[i].c){
				dis[Ed[i].end] = dis[t] + Ed[i].c;
				if(!vis[Ed[i].end]){vis[Ed[i].end] = 1; q.push(Ed[i].end);}
			}
	}
	return dis[T] < 0;
}

int cur[_];
int dfs(int x , int mn){
	if(x == T) return mn;
	int sum = 0; vis[x] = 1;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].f && dis[Ed[i].end] == dis[x] + Ed[i].c && !vis[Ed[i].end]){
			int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f));
			sum += t; Ed[i].f -= t; Ed[i ^ 1].f += t; if(sum == mn) break;
		}
	vis[x] = 0; return sum;
}

int main(){
	int N1 , N2 , M , R , B , sum = 0; cin >> N1 >> N2 >> M >> R >> B; T = N1 + N2 + 1;
	for(int i = 1 ; i <= N1 + N2 ; ++i) cin >> col[i];
	for(int i = 1 ; i <= M ; ++i){
		int p , q; cin >> p >> q; q += N1; ++d[p]; ++d[q]; sum += B;
		addE(p , q , 1 , -B); addE(p , q , 1 , R);
	}
	for(int i = 1 ; i <= N1 ; ++i){
		switch(col[i]){
		case 'R': addE(S , i , d[i] + 1 , -2e5); addE(S , i , d[i] - 1); sum += 2e5 * (d[i] + 1); break;
		case 'B': addE(S , i , d[i] - 1); break;
		case 'U': addE(S , i , 2 * d[i]); break;
		}
		if(col[i] != 'U' && !d[i]){puts("-1"); return 0;}
	}
	for(int i = N1 + 1 ; i <= N1 + N2 ; ++i){
		switch(col[i]){
		case 'R': addE(i , T , d[i] + 1 , -2e5); addE(i , T , d[i] - 1); sum += 2e5 * (d[i] + 1); break;
		case 'B': addE(i , T , d[i] - 1); break;
		case 'U': addE(i , T , 2 * d[i]); break;
		}
		if(col[i] != 'U' && !d[i]){puts("-1"); return 0;}
	}
	while(SPFA()){
		memcpy(cur , head , sizeof(int) * (T + 1));
		sum += dis[T] * dfs(S , 1e9);
	}
	cout << (sum > 1e5 ? -1 : sum) << endl;
	if(sum <= 1e5)
		for(int i = 1 ; i <= M ; ++i)
			switch(Ed[4 * i - 2].f + Ed[4 * i].f){
			case 0: putchar('R'); break;
			case 1: putchar('U'); break;
			case 2: putchar('B'); break;
			}
	return 0;
}