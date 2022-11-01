#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int main(){
	int N , M;
	N = read();
	M = read();
	cout << (int)(ceil(N * 2.0 / M - 1e-8) + ceil(N  * 5.0 / M - 1e-8) + ceil(N * 8.0 / M - 1e-8));
	return 0;
}