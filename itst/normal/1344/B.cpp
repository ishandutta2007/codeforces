#include<bits/stdc++.h>
using namespace std;

char Map[1003][1003]; int N , M;

int main(){
	scanf("%d %d" , &N , &M); for(int i = 1 ; i <= N ; ++i) scanf("%s" , Map[i] + 1);
	bool flg1 = 0 , flg2 = 0;
	for(int i = 1 ; i <= N ; ++i){
		int mn = 1e9 , mx = 0 , cnt = 0;
		for(int j = 1 ; j <= M ; ++j) if(Map[i][j] == '#'){++cnt; mn = min(mn , j); mx = j;}
		if(cnt && mx - mn + 1 != cnt){cout << "-1"; return 0;}
		flg1 |= !cnt;
	}
	for(int j = 1 ; j <= M ; ++j){
		int mn = 1e9 , mx = 0 , cnt = 0;
		for(int i = 1 ; i <= N ; ++i) if(Map[i][j] == '#'){++cnt; mn = min(mn , i); mx = i;}
		if(cnt && mx - mn + 1 != cnt){cout << "-1"; return 0;}
		flg2 |= !cnt;
	}
	if(flg1 ^ flg2){cout << -1; return 0;}
	queue < pair < int , int > > q; const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(Map[i][j] == '#'){
				++ans; q.push(make_pair(i , j)); Map[i][j] = '.';
				while(!q.empty()){
					int x = q.front().first , y = q.front().second; q.pop();
					for(int p = 0 ; p < 4 ; ++p){
						int X = x + dir[p][0] , Y = y + dir[p][1];
						if(Map[X][Y] == '#'){
							q.push(make_pair(X , Y)); Map[X][Y] = 0;
						}
					}
				}
			}
	cout << ans;
	return 0;
}