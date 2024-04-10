#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int _ = (1 << 17) + 3 , MOD = 1e9 + 7;
#define lowbit(x) (x & (-x))
int fib[_] , arr[_] , cnt1[_] , Or[18][_] , ansOr[_] , tmp[_] , And[_] , Xor[_] , N;

void orFWT(int *arr , long long tp){
	for(int i = 0 ; i < 17 ; ++i)
		for(int j = 0 ; j < 1 << 17 ; j += 1 << (i + 1))
			for(int k = 0 ; k < 1 << i ; ++k)
				arr[(1 << i) + j + k] = (arr[(1 << i) + j + k] + tp * arr[j + k] + MOD) % MOD;
}

void andFWT(int *arr , long long tp){
	for(int i = 0 ; i < 17 ; ++i)
		for(int j = 0 ; j < 1 << 17 ; j += 1 << (i + 1))
			for(int k = 0 ; k < 1 << i ; ++k)
				arr[j + k] = (arr[j + k] + tp * arr[(1 << i) + j + k] + MOD) % MOD;
}

void xorFWT(int *arr , long long tp){
	for(int i = 0 ; i < 17 ; ++i)
		for(int j = 0 ; j < 1 << 17 ; j += 1 << (i + 1))
			for(int k = 0 ; k < 1 << i ; ++k){
				int x = arr[j + k] , y = arr[(1 << i) + j + k];
				arr[j + k] = (x + y) % MOD;
				arr[(1 << i) + j + k] = (x - y + MOD) % MOD;
				if(tp == -1){
					if(arr[j + k] & 1) arr[j + k] += MOD;
					arr[j + k] >>= 1;
					if(arr[(1 << i) + j + k] & 1) arr[(1 << i) + j + k] += MOD;
					arr[(1 << i) + j + k] >>= 1;
				}
			}
}

void init(){
	for(int i = 1 ; i < 1 << 17 ; ++i)
		cnt1[i] = cnt1[i - lowbit(i)] + 1;
	fib[1] = 1;
	for(int i = 2 ; i < 1 << 17 ; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	init();
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int p = read();
		++arr[p]; ++Or[cnt1[p]][p];
	}
	memcpy(And , arr , sizeof(arr)); memcpy(Xor , arr , sizeof(arr));
	for(int i = 0 ; i <= 17 ; ++i)
		orFWT(Or[i] , 1);
	for(int i = 0 ; i <= 17 ; ++i){
		memset(tmp , 0 , sizeof(tmp));
		for(int j = 0 ; j <= i ; ++j)
			for(int k = 0 ; k < 1 << 17 ; ++k)
				tmp[k] = (tmp[k] + 1ll * Or[j][k] * Or[i - j][k]) % MOD;
		orFWT(tmp , -1);
		for(int k = 0 ; k < 1 << 17 ; ++k)
			if(cnt1[k] == i)
				ansOr[k] = tmp[k];
	}
	xorFWT(Xor , 1);
	for(int i = 0 ; i < 1 << 17 ; ++i)
		Xor[i] = 1ll * Xor[i] * Xor[i] % MOD;
	xorFWT(Xor , -1);
	for(int i = 0 ; i < 1 << 17 ; ++i){
		ansOr[i] = 1ll * ansOr[i] * fib[i] % MOD;
		And[i] = 1ll * And[i] * fib[i] % MOD;
		Xor[i] = 1ll * Xor[i] * fib[i] % MOD;
	}
	andFWT(ansOr , 1); andFWT(And , 1); andFWT(Xor , 1);
	for(int i = 0 ; i < 1 << 17 ; ++i)
		And[i] = 1ll * ansOr[i] * And[i] % MOD * Xor[i] % MOD;
	andFWT(And , -1);
	int ans = 0;
	for(int i = 1 ; i < 1 << 17 ; i <<= 1)
		ans = (ans + And[i]) % MOD;
	cout << ans;
	return 0;
}