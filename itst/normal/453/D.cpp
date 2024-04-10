#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
const int MAXN = (1 << 20) + 7;
int E[MAXN] , trans[MAXN] , B[21] , N , M , T , MOD , phi;
void getPhi(){
	phi = MOD;
	int tmp = MOD;
	for(int i = 2 ; i * i <= tmp ; ++i)
		if(tmp % i == 0){
			phi = phi / i * (i - 1);
			while(tmp % i == 0) tmp /= i;
		}
	if(tmp - 1) phi = phi / tmp * (tmp - 1);
}
int mul(unsigned int x , unsigned int y){
	int sum = x * y - (long long)((long double)x / MOD * y + 0.5) * MOD;
	if(sum < 0) sum += MOD;
	return sum;
}
int poww(int a , int b){
	int times = 1;
	if(b > phi)
		b = b % phi + phi;
	while(b){
		if(b & 1) times = mul(times , a);
		a = mul(a , a);
		b >>= 1;
	}
	return times;
}
void FWT(int *arr){
	for(int i = 1 ; i < N ; i <<= 1)
		for(int j = 0 ; j < N ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = arr[i + j + k];
				arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
				arr[i + j + k] = x - y < 0 ? x - y + MOD : x - y;
			}
}
int popcount(int x){
	int cnt = 0;
	while(x){
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	M = read(); N = 1 << M;
	T = read(); MOD = read() * N;
	getPhi();
	for(int i = 0 ; i < N ; ++i)
		E[i] = read() % MOD;
	for(int i = 0 ; i <= M ; ++i)
		B[i] = read() % MOD;
	for(int i = 0 ; i < N ; ++i)
		trans[i] = B[popcount(i)];
	FWT(E); FWT(trans);
	for(int i = 0 ; i < N ; ++i)
		E[i] = mul(E[i] , poww(trans[i] , T));
	FWT(E);
	for(int i = 0 ; i < N ; ++i)
		printf("%I64d\n" , E[i] / N);
	return 0;
}