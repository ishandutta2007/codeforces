#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;

int N , M , K , dp[53][20003] , sum[503][20003];

int main(){
	cin>>N>>M>>K;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1; j <= M ; ++j){
			cin>>sum[i][j]; sum[i][j] += sum[i][j -1 ];
		}
	memset(dp , -0x1f , sizeof(dp));
	for(int i = 1 ; i <= M - K + 1 ; ++i) dp[1][i] = sum[1][i + K - 1] - sum[1][i - 1] + sum[2][i + K - 1] - sum[2][i - 1];
	for(int i = 2 ; i <= N ; ++i){
		deque < int > q;
		for(int j = 1 ; j <= K && j <= M - K + 1 ; ++j){
			while(!q.empty() && dp[i - 1][q.back()] + sum[i][q.back() - 1] < dp[i - 1][j] + sum[i][j - 1]) q.pop_back();
			q.push_back(j);
		}
		for(int j = 1 ; j <= M - K + 1 ; ++j){
			dp[i][j] = max(dp[i][j] , dp[i - 1][q.front()] + sum[i][q.front() - 1] - sum[i][j - 1]);
			if(q.front() == j) q.pop_front();
			if(j + K <= M - K + 1){
				int t = j + K;
				while(!q.empty() && dp[i - 1][q.back()] + sum[i][q.back() - 1] < dp[i - 1][t] + sum[i][t - 1]) q.pop_back();
				q.push_back(t);
			}
		}
		q.clear();
		for(int j = 1 ; j <= M - K + 1 && j <= K ; ++j){
			int t = M - K + 2 - j;
			while(!q.empty() && dp[i - 1][q.back()] - sum[i][q.back() + K - 1] < dp[i - 1][t] - sum[i][t + K - 1])
				q.pop_back();
			q.push_back(t);
		}
		for(int j = M - K + 1 ; j ; --j){
			dp[i][j] = max(dp[i][j] , dp[i - 1][q.front()] - sum[i][q.front() + K - 1] + sum[i][j + K - 1]);
			if(q.front() == j) q.pop_front();
			if(j - K > 0){
				int t = j - K;
				while(!q.empty() && dp[i - 1][q.back()] - sum[i][q.back() + K - 1] < dp[i - 1][t] - sum[i][t + K - 1])
					q.pop_back();
				q.push_back(t);
			}
		}
		int mx = 0;
		for(int j = 1 ; j <= M - K + 1; ++j){
			mx = max(mx , dp[i - 1][j]);
			if(j + K <= M - K + 1) dp[i][j + K] = max(dp[i][j + K] , mx + sum[i][j + K + K - 1] - sum[i][j + K - 1]);
		}
		mx = 0;
		for(int j = M - K + 1 ; j ; --j){
			mx = max(mx , dp[i - 1][j]);
			if(j - K > 0) dp[i][j - K] = max(dp[i][j - K] , mx + sum[i][j - 1] - sum[i][j - K - 1]);
		}
		for(int j = 1 ; j <= M - K + 1 ; ++j)
			dp[i][j] += sum[i + 1][j + K - 1] - sum[i + 1][j - 1];
	}
	int mx = 0;
	for(int i = 1 ; i <= M - K + 1 ; ++i) mx = max(mx , dp[N][i]);
	cout << mx;
	return 0;
}