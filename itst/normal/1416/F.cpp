#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , __ = 2e6 + 7; struct Edge{int end , upEd , f;}Ed[__]; 
int head[_] , cntEd = 1 , S , T;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , 0);}

int dep[_] , cur[_]; queue < int > q;
bool bfs(){
	memset(dep , 0 , sizeof(int) * (T + 4)); while(!q.empty()) q.pop();
	dep[S] = 1; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(!dep[Ed[i].end] && Ed[i].f){
				dep[Ed[i].end] = dep[t] + 1; q.push(Ed[i].end);
				if(Ed[i].end == T){memcpy(cur , head , sizeof(int) * (T + 4)); return 1;}
			}
	}
	return 0;
}

int dfs(int x , int mn){
	if(x == T) return mn;
	int sum = 0;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(dep[Ed[i].end] == dep[x] + 1 && Ed[i].f){
			int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f)); Ed[i].f -= t; Ed[i ^ 1].f += t;
			if((sum += t) == mn) break;
		}
	return sum;
}

#define id(i,j) ((i) * M + (j) + 1)
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int CASE , N , M;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> CASE ; CASE ; --CASE){
		cntEd = 1; memset(head , 0 , sizeof(head));
		cin >> N >> M; vector < vector < int > > pot(N , vector < int > (M));
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < M ; ++j)
				cin >> pot[i][j];
		T = N * M + 1; int SS = N * M + 2 , TT = N * M + 3 , num = 0;
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < M ; ++j){
				int cnt = 0;
				for(int k = 0 ; k < 4 ; ++k){
					int x = i + dir[k][0] , y = j + dir[k][1];
					cnt += x >= 0 && y >= 0 && x < N && y < M && pot[x][y] < pot[i][j];
				}
				if((i + j) & 1){
					if(cnt) addE(SS , id(i , j) , 1);
					else{++num; addE(S , id(i , j) , 1); addE(SS , T , 1);}
					for(int k = 0 ; k < 4 ; ++k){
						int x = i + dir[k][0] , y = j + dir[k][1];
						if( x >= 0 && y >= 0 && x < N && y < M && pot[x][y] == pot[i][j])
							addE(id(i , j) , id(x , y) , 1);
					}
				}else
					if(cnt) addE(id(i , j) , TT , 1);
					else{++num; addE(S , TT , 1); addE(id(i , j) , T , 1);}
			}
		addE(TT , SS , 1e9); int sum = 0; while(bfs()) sum += dfs(S , 1e9);
		if(sum != num) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			vector < vector < int > > ans(N , vector < int > (M));
			vector < vector < char > > dr(N , vector < char > (M));
			for(int i = 0 ; i < N ; ++i)
				for(int j = 0 ; j < M ; ++j)
					if((i + j) & 1)
						for(int p = head[id(i , j)] ; p ; p = Ed[p].upEd)
							if(Ed[p].end != S && Ed[p].end != T && Ed[p].end != SS && Ed[p].end != TT && !Ed[p].f){
								int t = Ed[p].end , x = (t - 1) / M , y = (t - 1) % M;
								ans[i][j] = 1; ans[x][y] = pot[x][y] - 1;
								switch((x - i) * 2 + (y - j)){
								case -2: dr[i][j] = 'U'; dr[x][y] = 'D'; break;
								case -1: dr[i][j] = 'L'; dr[x][y] = 'R'; break;
								case 1: dr[i][j] = 'R'; dr[x][y] = 'L'; break;
								case 2: dr[i][j] = 'D'; dr[x][y] = 'U'; break;
								}
							}
			for(int i = 0 ; i < N ; ++i)
				for(int j = 0 ; j < M ; ++j)
					if(!ans[i][j])
						for(int k = 0 ; k < 4 ; ++k){
							int x = i + dir[k][0] , y = j + dir[k][1];
							if(x >= 0 && y >= 0 && x < N && y < M && pot[x][y] < pot[i][j]){
								dr[i][j] = "RLDU"[k]; ans[i][j] = pot[i][j] - pot[x][y]; break;
							}
						}
			for(int i = 0 ; i < N ; ++i)
				for(int j = 0 ; j < M ; ++j)
					cout << ans[i][j] << " \n"[j == M - 1];
			for(int i = 0 ; i < N ; ++i)
				for(int j = 0 ; j < M ; ++j)
					cout << dr[i][j] << " \n"[j == M - 1];
		}
	}
	return 0;
}