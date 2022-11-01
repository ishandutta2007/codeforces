#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
//This code is written by Itst
using namespace std;

const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char Map[23][23];
int val[9] , add[23][23] , dp[23][23][1 << 9] , sum[2007];
int N , M , D , X , Y , logg2[2007];
bool vis[23][23][1 << 9];
struct zt{
	int x , y , cir;
};
queue < zt > q;

void bfs(int i , int j){
	memset(dp , 0x3f , sizeof(dp));
	dp[i][j][0] = 0;
	vis[i][j][0] = 1;
	q.push((zt){i , j , 0});
	while(!q.empty()){
		zt t = q.front();
		q.pop();
		vis[t.x][t.y][t.cir] = 0;
		for(int i = 0 ; i < 4 ; ++i){
			int p = t.x + dir[i][0] , s = t.y + dir[i][1] , r = t.cir;
			if(i == 2) r ^= add[p][s];
			if(i == 3) r ^= add[p + 1][s];
			if((Map[p][s] == '.' || Map[p][s] == 'S') && dp[p][s][r] > dp[t.x][t.y][t.cir] + 1){
				dp[p][s][r] = dp[t.x][t.y][t.cir] + 1;
				if(!vis[p][s][r]){
					vis[p][s][r] = 1;
					q.push((zt){p , s , r});
				}
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			cin >> Map[i][j];
			if(Map[i][j] >= '1' && Map[i][j] <= '9'){
				++D;
				for(int k = j + 1 ; k <= M ; ++k)
					add[i][k] += 1 << (Map[i][j] - '1');
			}
			else if(Map[i][j] == 'S'){X = i; Y = j;}
		}
	for(int i = 0 ; i < D ; ++i) cin >> val[i];
	for(int i = 2 ; i < 1 << D ; ++i) logg2[i] = logg2[i >> 1] + 1;
	for(int i = 1 ; i < 1 << D ; ++i)
		sum[i] = sum[i - (1 << logg2[i])] + val[logg2[i]];
	int ans = 0 , cnt = D;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(Map[i][j] == 'B'){
				for(int k = j + 1 ; k <= M ; ++k)
					add[i][k] += 1 << cnt;
				cnt++;
			}
	bfs(X , Y);
	for(int k = 1 ; k < 1 << D ; ++k)
		ans = max(ans , sum[k] - dp[X][Y][k]);
	cout << ans;
	return 0;
}