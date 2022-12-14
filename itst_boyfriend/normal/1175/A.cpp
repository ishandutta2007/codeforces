#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

int main(){
#define int long long
	int T;
	for(cin >> T ; T ; --T){
		int N , K , tms = 1 , cnt = 0;
		cin >> N >> K;
		while(N){
			cnt += N % K + 1;
			N /= K;
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}