#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int N , K , X[103] , Y[103] , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> X[i] >> Y[i];
		bool ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			bool flg = 1; for(int j = 1 ; j <= N ; ++j) flg &= abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= K;
			ans |= flg;
		}
		puts(ans ? "1" : "-1");
	}
	return 0;
}