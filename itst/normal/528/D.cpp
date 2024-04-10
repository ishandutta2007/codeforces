#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
//This code is written by Itst
using namespace std;

const char mod[] = "AGCT";
const int MOD = 998244353 , INV = 332748118 , G = 3 , MAXN = (1 << 19) + 7;
char s[MAXN] , t[MAXN];
int A[MAXN] , B[MAXN] , dir[MAXN] , sum[MAXN];
int S , T , K , need , inv;

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

void init(int len){
	need = 1;
	while(need < len)
		need <<= 1;
	inv = poww(need , MOD - 2);
	for(int i = 1 ; i < need ; ++i)
		dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
}

void NTT(int *arr , int type){
	for(int i = 1 ; i < need ; ++i)
		if(i < dir[i])
			arr[i] ^= arr[dir[i]] ^= arr[i] ^= arr[dir[i]];
	for(int i = 1 ; i < need ; i <<= 1){
		int wn = poww(type == 1 ? G : INV , (MOD - 1) / i / 2);
		for(int j = 0 ; j < need ; j += i << 1){
			long long w = 1;
			for(int k = 0 ; k < i ; ++k , w = w * wn % MOD){
				int x = arr[j + k] , y = arr[i + j + k] * w % MOD;
				arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
				arr[i + j + k] = x < y ? x - y + MOD : x - y;
			}
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	scanf("%d %d %d %s %s" , &S , &T , &K , s + 1 , t + 1);
	reverse(t + 1 , t + T + 1);
	init(S + T + 1);
	for(int i = 0 ; i < 4 ; ++i){
		memset(A , 0 , sizeof(int) * need);
		memset(B , 0 , sizeof(int) * need);
		for(int j = 1 ; j <= S ; ++j)
			if(s[j] == mod[i]){
				++A[max(1 , j - K)];
				if(j + K < S) --A[j + K + 1];
			}
		for(int j = 1 ; j <= S ; ++j)
			A[j] += A[j - 1];
		for(int j = 1 ; j <= S ; ++j)
			A[j] = (bool)A[j];
		for(int j = 1 ; j <= T ; ++j)
			if(t[j] == mod[i])
				B[j] = 1;
		NTT(A , 1); NTT(B , 1);
		for(int j = 0 ; j < need ; ++j)
			A[j] = 1ll * A[j] * B[j] % MOD;
		NTT(A , -1);
		for(int j = T + 1 ; j <= S + 1 ; ++j)
			sum[j] += 1ll * A[j] * inv % MOD;
	}
	int cnt = 0;
	for(int i = T + 1 ; i <= S + 1 ; ++i)
		cnt += sum[i] == T;
	cout << cnt;
	return 0;
}