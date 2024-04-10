#include<bits/stdc++.h>
using namespace std;

int dp[303][103][103] , N , A[103] , L[103] , l[103] , r[103] , lsh[303] , mxr[303] , mx[303] , cnt;
vector < int > in[303] , imp[303];

int cmp(int x , int y){return r[x] < r[y] ? y : x;}

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		cin >> A[i] >> L[i]; lsh[++cnt] = l[i] = A[i] - L[i]; lsh[++cnt] = A[i]; lsh[++cnt] = r[i] = A[i] + L[i];
	}
	sort(lsh + 1 , lsh + cnt + 1); cnt = unique(lsh + 1 , lsh + cnt + 1) - lsh - 1;
	for(int i = 1 ; i <= N ; ++i){
		l[i] = lower_bound(lsh + 1 , lsh + cnt + 1 , l[i]) - lsh;
		A[i] = lower_bound(lsh + 1 , lsh + cnt + 1 , A[i]) - lsh;
		for(int j = l[i] ; j < A[i] ; ++j) in[j].push_back(i);
		imp[A[i]].push_back(i);
	}
	for(int i = 1 ; i < cnt ; ++i){
		for(auto t : imp[i]) mx[i] = cmp(mx[i] , t);
		for(auto t : imp[i]) for(auto x : imp[i]) if(x != t) mxr[t] = cmp(mxr[t] , x);
	}
	memset(dp , -0x3f , sizeof(dp)); dp[1][0][0] = 0;
	for(int i = 1 ; i < cnt ; ++i){
		for(int j = 0 ; j <= N ; ++j)
			for(int k = 0 ; k <= N ; ++k)
				if(dp[i][j][k] >= 0){
					int nj = lsh[A[j]] + L[j] == lsh[i] ? 0 : j , nk = lsh[A[k]] == lsh[i] ? 0 : k;
					nj = cmp(nj , k && !nk ? mxr[k] : mx[i]); dp[i + 1][nj][nk] = max(dp[i + 1][nj][nk] , dp[i][j][k]);
				}
		if(dp[i + 1][0][0] >= 0)
			for(auto t : in[i]) dp[i + 1][0][t] = max(dp[i + 1][0][t] , dp[i + 1][0][0]);
		for(int j = 0 ; j <= N ; ++j)
			for(int k = 0 ; k <= N ; ++k)
				if(dp[i + 1][j][k] >= 0) dp[i + 1][j][k] += (bool)(j | k) * (lsh[i + 1] - lsh[i]);
	}
	int ans = 0; for(int i = 0 ; i <= N ; ++i) for(int j = 0 ; j <= N ; ++j) ans = max(ans , dp[cnt][i][j]);
	cout << ans; return 0;
}