#include<bits/stdc++.h>
#define ld long double
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e4 + 10;
ld r[MAXN];
int T;

void work(){
	for(T = read() ; T ; --T){
		ld R1 = read() , R2 = read();
		int K = read();
		r[0] = 1 / (R1 - R2);
		R1 = 1 / R1;
		R2 = 1 / R2;
		r[1] = r[0] + R2 - R1;
		for(int i = 2 ; i <= K ; ++i)
			r[i] = (r[i - 1] + R2 - R1) * 2 - r[i - 2];
		cout << fixed << setprecision(10) << 1 / r[K] << '\n';
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	work();
	return 0;
}