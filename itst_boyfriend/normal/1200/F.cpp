#include<bits/stdc++.h>
using namespace std;

int ed[1003][11] , N , K[1003] , M[1003] , loop[1003][2520];
int vis[1003][2520] , vis1[1003];

int dfs(int x , int c){
	c = (c + K[x] % 2520 + 2520) % 2520;
	if(loop[x][c] != -1) return loop[x][c];
	if(vis[x][c]){
		int p = x , q = c , cnt = 0;
		do{
			int t = ed[p][q % M[p]];
			p = t; q = (q + K[p] % 2520 + 2520) % 2520;
			cnt += !vis1[p]; vis1[p] = 1;
		}while(p != x || q != c);
		do{
			int t = ed[p][q % M[p]];
			p = t; q = (q + K[p] % 2520 + 2520) % 2520;
			vis1[p] = 0;
		}while(p != x || q != c);
		return loop[x][c] = cnt;
	}
	vis[x][c] = 1; int t = ed[x][c % M[x]];
	loop[x][c] = dfs(t , c); vis[x][c] = 0; return loop[x][c];
}

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> K[i];
	for(int i = 1 ; i <= N ; ++i){
		cin >> M[i];
		for(int j = 0 ; j < M[i] ; ++j) cin >> ed[i][j];
	}
	memset(loop , -1 , sizeof(loop));
	int Q;
	for(cin >> Q ; Q ; --Q){
		int x , y; cin >> x >> y;
		cout << dfs(x , (y % 2520 + 2520) % 2520) << endl;
	}
	return 0;
}