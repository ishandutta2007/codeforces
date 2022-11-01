#include<bits/stdc++.h>
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

int point[51][3] , N;

void solve(int l , int r , int dir){
	if(l == r)
		printf("(%01d*abs(((1-abs((t-%d)))+abs((abs((t-%d))-1)))))" , point[l][dir] / 2 , l , l);
	else{
		putchar('(');
		solve(l , l + r >> 1 , dir);
		putchar('+');
		solve((l + r >> 1) + 1 , r , dir);
		putchar(')');
	}
}

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		point[i][0] = read();
		point[i][1] = read();
		point[i][2] = read();
	}
	solve(1 , N , 0);
	putchar('\n');
	solve(1 , N , 1);
	return 0;
}