#include<bits/stdc++.h>
using namespace std;

#define ld long double
vector < int > nxt[53]; int N , sz[53]; ld dp[53][53] , tmp[53];

void DP(int x , int p){
	sz[x] = dp[x][0] = 1;
	for(auto t : nxt[x])
		if(t != p){
			DP(t , x); memset(tmp , 0 , sizeof(tmp));
			for(int p = 0 ; p < sz[x] ; ++p)
				for(int q = 0 ; q < sz[t] ; ++q){
					tmp[p + q] += dp[x][p] * dp[t][q] * (0.5 / (sz[t] - q) - 1);
					tmp[p + q + 1] += dp[x][p] * dp[t][q];
				}
			memcpy(dp[x] , tmp , sizeof(tmp)); sz[x] += sz[t];
		}
}

int main(){
	cin >> N; for(int i = 1 , x , y ; i < N ; ++i){cin >> x >> y; nxt[x].push_back(y); nxt[y].push_back(x);}
	for(int i = 1 ; i <= N ; ++i){
		memset(dp , 0 , sizeof(dp)); DP(i , 0); ld sum = 1;
		for(auto t : nxt[i]){ld num = 0; for(int j = 0 ; j < sz[t] ; ++j) num += dp[t][j] * 0.5 / (sz[t] - j); sum *= num;}
		cout << setprecision(10) << sum << endl;
	}
	return 0;
}