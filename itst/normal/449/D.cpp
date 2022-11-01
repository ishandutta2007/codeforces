#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int MOD = 1e9 + 7 , _ = 1 << 20 | 1;
int arr[_] , pw2[_] , N;

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) ++arr[read()];
	pw2[0] = 1; for(int i = 1 ; i <= N ; ++i) pw2[i] = (pw2[i - 1] << 1) % MOD;
	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 1 << 20 ; ++j)
			if(!(j >> i & 1)) arr[j] += arr[j | (1 << i)];
	int sum = 0;
	for(int i = 0 ; i < 1 << 20 ; ++i)
		sum = (sum + (__builtin_popcount(i) & 1 ? -1 : 1) * pw2[arr[i]]) % MOD;
	cout << (sum + MOD) % MOD; return 0;
}