#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; int val[1 << 20] , cnt[1 << 20] , N;

void FWT(int *arr , int tp){
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < 1 << N ; j += 2 << i)
			for(int k = 0 ; k < 1 << i ; ++k){
				int x = arr[j + k] , y = arr[(1 << i) + j + k];
				arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
				arr[(1 << i) + j + k] = x < y ? x + MOD - y : x - y;
				if(tp == -1){
					arr[j + k] = (arr[j + k] & 1 ? arr[j + k] + MOD : arr[j + k]) / 2;
					arr[(1 << i) + j + k] = (arr[(1 << i) + j + k] & 1 ? arr[(1 << i) + j + k] + MOD : arr[(1 << i) + j + k]) / 2;
				}
			}
}

int main(){
	scanf("%d" , &N);
	for(int i = 0 ; i < 1 << N ; ++i){char c = getchar(); while(!isdigit(c)) c = getchar(); val[i] = c - '0';}
	FWT(val , 1); for(int i = 0 ; i < 1 << N ; ++i) val[i] = 1ll * val[i] * val[i] % MOD;
	FWT(val , -1); int ans = 0; cnt[0] = 1;
	for(int i = 0 ; i < 1 << N ; ++i) cnt[i] = (cnt[i >> 1] << (i & 1)) % MOD;
	for(int i = 0 ; i < 1 << N ; ++i) ans = (ans + 1ll * cnt[(1 << N) - 1 - i] * val[i]) % MOD;
	cout << 3ll * ans % MOD; return 0;
}