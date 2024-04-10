#include<bits/stdc++.h>
using namespace std;

const int _ = 3003;
int dis[_][_] , s1 , t1 , l1 , s2 , t2 , l2 , N , M;
vector < int > Ed[_];

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){
		int a , b; cin >> a >> b;
		Ed[a].push_back(b); Ed[b].push_back(a);
	}
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	for(int i = 1 ; i <= N ; ++i){
		memset(dis[i] , 0x3f , sizeof(dis[i]));
		queue < int > q; dis[i][i] = 0; q.push(i);
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(auto p : Ed[t])
				if(dis[i][p] > dis[i][t] + 1){
					dis[i][p] = dis[i][t] + 1; q.push(p);
				}
		}
	}
	if(dis[s1][t1] > l1 || dis[s2][t2] > l2){puts("-1"); return 0;}
	if(s1 == t1 && s2 == t2){cout << M; return 0;}
	else if(s1 == t1){cout << M - dis[s2][t2]; return 0;}
	else if(s2 == t2){cout << M - dis[s1][t1]; return 0;}
	else{
		int ans = dis[s1][t1] + dis[s2][t2];
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 1 ; j <= N ; ++j){
				if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
					ans = min(ans , dis[s1][i] + dis[s2][i] + dis[i][j] + dis[j][t1] + dis[j][t2]);
				if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[t2][i] + dis[i][j] + dis[j][s2] <= l2)
					ans = min(ans , dis[s1][i] + dis[t2][i] + dis[i][j] + dis[j][t1] + dis[j][s2]);
			}
		cout << M - ans;
	}
	return 0;
}