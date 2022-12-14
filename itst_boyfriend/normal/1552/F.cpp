#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int P = 998244353; int N , X[200003] , Y[200003] , S[200003] , f[200003] , Sf[200003];

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i){X[i] = read(); Y[i] = read(); S[i] = read();}
	for(int i = 1 ; i <= N ; ++i){
		int t = lower_bound(X + 1 , X + N + 1 , Y[i]) - X;
		f[i] = (0ll + Sf[i - 1] - Sf[t - 1] + X[i] - Y[i] + P) % P;
		Sf[i] = (Sf[i - 1] + f[i]) % P;
	}
	int L = 1;
	for(int i = 1 ; i <= N ; ++i) L = (0ll + L + X[i] - X[i - 1] + (S[i] ? f[i] : 0)) % P;
	cout << L; return 0;
}