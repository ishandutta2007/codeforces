#include<vector>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

const int _ = 1e5 + 7;
int dp[_] , pm[_] , pre[_] , N , T; bool out[_]; vector < int > pot[_];

int main(){
	for(scanf("%d" , &T) ; T ; --T){
		scanf("%d" , &N); vector < vector < int > > ans;
		for(int i = 1 ; i <= N ; ++i) scanf("%d" , &pm[i]);
		int cnt = 0; memset(out , 0 , sizeof(bool) * (N + 1));
		while(cnt != N){
			int K = 1; while(K * (K + 1) / 2 < (N - cnt)) ++K;
			memset(dp , 0 , sizeof(int) * (N + 1)); int len = 0;
			for(int i = 1 ; i <= N ; ++i)
				if(!out[i]){
					int L = 0 , R = len;
					while(L < R){
						int mid = (L + R + 1) >> 1;
						pm[dp[mid]] < pm[i] ? L = mid : R = mid - 1;
					}
					pre[i] = dp[L]; dp[L + 1] = i; if(L == len) ++len;
				}
			if(len >= K){
				cnt += len; vector < int > tmp; int t = dp[len];
				while(t){tmp.push_back(pm[t]); out[t] = 1; t = pre[t];}
				reverse(tmp.begin() , tmp.end()); ans.push_back(tmp);
			}
			else{
				for(int i = 1 ; i <= len ; ++i) pot[i].clear();
				memset(dp , 0 , sizeof(int) * (N + 1)); len = 0; cnt = N;
				for(int i = 1 ; i <= N ; ++i)
					if(!out[i]){
					int L = 0 , R = len;
					while(L < R){
						int mid = (L + R + 1) >> 1;
						pm[dp[mid]] < pm[i] ? L = mid : R = mid - 1;
					}
					dp[L + 1] = i; pot[L + 1].push_back(pm[i]); if(L == len) ++len;
				}
				for(int i = 1 ; i <= len ; ++i) ans.push_back(pot[i]);
			}
		}
		printf("%d\n" , ans.size());
		for(int i = 0 ; i < ans.size() ; ++i){
			printf("%d " , ans[i].size());
			for(int j = 0 ; j < ans[i].size() ; ++j)
				printf("%d%c" , ans[i][j] , " \n"[j + 1 == ans[i].size()]);
		}
	}
}