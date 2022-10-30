#include<bits/stdc++.h>
using namespace std;

int arr[13][2003] , mx[2003] , id[2003] , dp[1 << 12] , val[1 << 12] , Mx[1 << 12] , N , M , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; memset(dp , 0 , sizeof(dp)); memset(mx , 0 , sizeof(mx));
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < M ; ++j){
				cin >> arr[i][j]; mx[j] = max(mx[j] , arr[i][j]);
			}
		for(int j = 0 ; j < M ; ++j) id[j] = j;
		sort(id , id + M , [&](int p , int q){return mx[p] > mx[q];});
		for(int i = 0 ; i < min(N , M) ; ++i){
			memset(Mx , 0 , sizeof(Mx));
#define lowbit(x) ((x) & -(x))
			for(int j = 0 ; j < N ; ++j)
				for(int k = 1 ; k < 1 << N ; ++k){
					val[k] = val[k - lowbit(k)] + arr[(j + (int)log2(lowbit(k) + 0.1)) % N][id[i]];
					Mx[k] = max(Mx[k] , val[k]);
				}
			for(int k = (1 << N) - 1 ; k >= 0 ; --k){
				int s = k; while(s){dp[k] = max(dp[k] , dp[s ^ k] + Mx[s]); s = (s - 1) & k;}
			}
		}
		cout << dp[(1 << N) - 1] << endl;
	}
	return 0;
}