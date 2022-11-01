#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 3e5 + 7; int T , N , M , C[_] , pot[_];

int main(){
	for(T = read() ; T ; --T){
		N = read(); M = read(); for(int i = 1 ; i <= M ; ++i) pot[i] = 0;
		long long sum = 0; int pos = M;
		for(int i = 1 ; i <= N ; ++i) ++pot[read()];
		for(int i = 1 ; i <= M ; ++i){C[i] = read(); sum += 1ll * pot[i] * C[i];}
		for(int j = 1 ; j <= M ; ++j){
			while(!pot[pos]){--pos;} if(pos < j) break;
			sum = sum + C[j] - C[pos]; --pot[pos];
		}
		cout << sum << '\n';
	}
	return 0;
}