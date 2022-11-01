#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; vector < int > num; int p , e , dp[3333][2][2] , tp[3333][2][2];

void change(){
	vector < int > ans , lft = num;
	while(lft.size()){
		long long sum = 0; num = lft; lft.clear();
		for(auto t : num){sum = sum * 10 + t; if(lft.size() || sum / p){lft.push_back(sum / p); sum %= p;}}
		ans.push_back(sum);
	}
	num = ans;
}

int calc(int l){return (l <= p - 1 ? 1ll * (l + 2) * (l + 1) / 2 : (1ll * p * p - 1ll * (2 * (p - 1) - l) * (2 * (p - 1) - l + 1) / 2)) % P;}
int calc(int l , int r){l = max(l , 0); r = min(r , 2 * (p - 1)); return l > r ? 0 : (calc(r) - calc(l - 1)) % P;}

int main(){
	cin >> p >> e; string A; cin >> A; for(int i = 0 ; i < A.size() ; ++i) num.push_back(A[i] - '0');
	if(A == "0"){puts("0"); return 0;} change(); if(e >= num.size()){puts("0"); return 0;}
	dp[0][0][1] = 1;
	for(int i = 0 ; i < num.size() ; ++i){
		memset(tp , 0 , sizeof(tp));
		for(int j = 0 ; j <= i ; ++j)
			for(int k = 0 ; k < 2 ; ++k)
				for(int l = 0 ; l < 2 ; ++l)
					if(dp[j][k][l])
						for(int s = 0 ; s < 2 ; ++s){
							tp[j + s][s][1] = (tp[j + s][s][1] + 1ll * dp[j][k][l] * calc(s * p - k , s * p + num[i] - 1 - k)) % P;
							tp[j + s][s][l] = (tp[j + s][s][l] + 1ll * dp[j][k][l] * calc(s * p + num[i] - k , s * p + num[i] - k)) % P;
							tp[j + s][s][0] = (tp[j + s][s][0] + 1ll * dp[j][k][l] * calc(s * p + num[i] + 1 - k , s * p + p - 1 - k)) % P;
						}
		memcpy(dp , tp , sizeof(tp));
	}
	int sum = 0; for(int i = e ; i < num.size() ; ++i) sum = (sum + dp[i][0][1]) % P;
	cout << (sum + P) % P; return 0;
}