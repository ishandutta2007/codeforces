#include<bits/stdc++.h>
using namespace std;

int dp[503][503] , pre[503][503] , N , M , arr[2][503];

void output(int x , int y){
	if(!x) return;
	output(pre[x][y] , y - 1); if(x != pre[x][y]) printf("%d " , arr[0][x]);
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[0][i];
	cin >> M; for(int i = 1 ; i <= M ; ++i) cin >> arr[1][i];
	for(int j = 1 ; j <= M ; ++j){
		int mx = 0 , p = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(arr[0][i] == arr[1][j]){dp[i][j] = mx + 1; pre[i][j] = p;}
			else if(arr[0][i] < arr[1][j] && mx < dp[i][j - 1]){mx = dp[i][j - 1]; p = i;}
			if(dp[i][j] < dp[i][j - 1]){dp[i][j] = dp[i][j - 1]; pre[i][j] = i;}
		}
	}
	int ans = 0 , id = 0;
	for(int i = 1 ; i <= N ; ++i) if(ans < dp[i][M]){ans = dp[i][M]; id = i;}
	cout << ans << endl; output(id , M); return 0;
}