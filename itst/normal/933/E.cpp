#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

#define int long long
const int _ = 3e5 + 7;
int dp[_] , pre[_] , N , val[_];
vector < int > stp;

void move(int x){
	if(x == N) return;
	if(val[x] == 0 || val[x + 1] == 0) return;
	stp.push_back(x);
	int t = min(val[x] , val[x + 1]);
	val[x] -= t; val[x + 1] -= t;
}

signed main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> val[i];
	dp[1] = 0; dp[2] = val[1];
	for(int i = 3 ; i <= N + 1 ; ++i)
		if(dp[i - 3] + max(val[i - 1] , val[i - 2]) < dp[i - 2] + val[i - 1])
			dp[i] = dp[pre[i] = i - 3] + max(val[i - 1] , val[i - 2]);
		else dp[i] = dp[pre[i] = i - 2] + val[i - 1];
	for(int i = dp[N] < dp[N + 1] ? N : N + 1 ; i > 1 ; i = pre[i])
		if(pre[i] == i - 3){move(i - 2); move(i - 1); if(i > 3) move(i - 3);}
		else{move(i - 1); if(i > 2) move(i - 2);}
	cout << stp.size() << endl;
	for(int i = 0 ; i < stp.size() ; ++i) cout << stp[i] << endl;
	return 0;
}