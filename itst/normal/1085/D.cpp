#include<bits/stdc++.h>
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

const int MAXN = 1e5 + 10;
int in[MAXN] , N;

int main(){
	N = read();
	long double K = read();
	for(int i = 1 ; i < N ; ++i){
		++in[read()];
		++in[read()];
	}
	int cnt = 0;
	for(int i = 1 ; i <= N ; ++i)
		cnt += in[i] == 1;
	cout << fixed << setprecision(9) << K * 2 / cnt;
	return 0;
}