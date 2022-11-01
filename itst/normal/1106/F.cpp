#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 998244353 , G = 3;
int K;
struct matrix{
	int a[100][100];
	int* operator [](int x){return a[x];}
	matrix(){memset(a , 0 , sizeof(a));}
	matrix operator *(matrix b){
		matrix c;
		for(int i = 0 ; i < K ; ++i)
			for(int j = 0 ; j < K ; ++j)
				for(int k = 0 ; k < K ; ++k)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % (MOD - 1);
		return c;
	}
}S , T;

inline int gcd(int a , int b){
	int r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

inline int poww(int a , int b , int mod = MOD){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return times;
}

map < int , int > Hash;

inline int BSGS(int x){
	int t = sqrt(MOD) + 1 , times = x;
    for(int i = 0 ; i < t ; i++){
        Hash[times] = i;
        times = times * G % MOD;
    }
    times = poww(G , t);
    int now = times;
    for(int i = 1 ; i <= t + 1 ; i++){
        if(Hash.count(now)){
            return i * t - Hash[now];
        }
        now = now * times % MOD;
    }
	return -1;
}

int phi(int x){
	int times = x;
	for(int i = 2 ; i * i <= x ; ++i){
		if(x % i == 0){
			times = times / i * (i - 1);
			while(x % i == 0)
				x /= i;
		}
	}
	if(x - 1)
		times = times / x * (x - 1);
	return times;
} 

signed main(){
	K = read();
	for(int i = 0 ; i < K ; ++i)
		T[K - i - 1][K - 1] = read() % (MOD - 1);
	int N = read() - K;
	int t = BSGS(read());
	for(int i = 0 ; i + 1 < K ; ++i)
		T[i + 1][i] = 1;
	S[0][K - 1] = 1;
	while(N){
		if(N & 1)
			S = S * T;
		T = T * T;
		N >>= 1;
	}
	int cur = S[0][K - 1] , p = gcd(cur , MOD - 1);
	if(t % p != 0)
		puts("-1");
	else{
		t /= p;
		cur /= p;
		int mod = (MOD - 1) / p; 
		cout << poww(G , poww(cur , phi(mod) - 1 , mod) * t % mod);
	}
	return 0;
}