#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int INF = 1e18 + 1 , _ = 3e4 + 7; int T , N , C , Q , A[_]; long long dp[_][5] , down[_][5] , up[_][5];

signed main(){
	for(T = read() ; T ; --T){
		N = read(); C = read(); Q = read(); for(int i = 1 ; i <= N + 1 ; ++i){memset(dp[i] , 0 , sizeof(dp[i]));}
		for(int i = 1 ; i <= N ; ++i){A[i] = read();} for(int i = 0 ; i <= C ; ++i) dp[N + 1][i] = 1;
		for(int i = N ; i ; --i)
			for(int j = 0 ; j <= C ; ++j){
				vector < pair < int , long long > > pot;
				for(int k = i ; k <= i + j && k <= N ; ++k) pot.push_back(make_pair(A[k] , dp[k + 1][j - (k - i)]));
				sort(pot.begin() , pot.end());
				for(auto t : pot){
					if(t.first == A[i]){down[i][j] = dp[i][j]; up[i][j] = min(dp[i][j] + t.second , INF);}
					dp[i][j] = min(dp[i][j] + t.second , INF);
				}
			}
		for(int i = 1 ; i <= N ; ++i) for(int j = 0 ; j <= C ; ++j){up[i][j] -= down[i][j]; down[i][j] = min(down[i][j] + down[i - 1][j] , INF);}
		while(Q--){
			int i = read() , j = read(); if(j > dp[1][C]){puts("-1"); continue;}
			int pos = 0 , lft = C , ans = 0;
			while(!ans){
				int L = pos , R = N;
				while(L < R){
					int mid = (L + R + 1) >> 1 , t = j - (down[mid][lft] - down[pos][lft]);
					t >= 1 && t <= up[mid][lft] ? L = mid : R = mid - 1;
				}
				if(L >= i) ans = A[i]; else{
					vector < pair < int , long long > > pot; j -= down[L][lft] - down[pos][lft]; ++L;
					for(int k = L ; k <= L + lft && k <= N ; ++k) pot.push_back(make_pair(A[k] , dp[k + 1][lft - (k - L)]));
					sort(pot.begin() , pot.end());
					for(auto t : pot)
						if(j > t.second) j -= t.second;
						else{
							int p = L; while(A[p] != t.first){++p;}
							if(i <= p) ans = A[L + p - i]; else{pos = p; lft -= p - L;}
							break;
						}
				}
			}
			printf("%lld\n" , ans);
		}
	}
	return 0;
}