#include<bits/stdc++.h>
#define int long long
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

const int ze = 5000 , mu = 4001 , pf = 3001 , n1 = 999 , ad = 2001;
int D , P , gauss[15][15] , C[15][15];

void init_0(){
	int dir = P - 1;
	for(int i = 1 ; 1 << i < P ; ++i){
		printf("+ %lld %lld %lld\n" , ze - i + 1 , ze - i + 1 , ze - i);
		if(dir & (1 << i))
			printf("+ %lld %lld %lld\n" , ze , ze - i , ze);
	}
}

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return times;
}

inline void init_gauss(){
	for(int i = 0 ; i <= D ; ++i)
		for(int j = 0 ; j <= D ; ++j)
			gauss[i][j] = poww(j , D - i);
	gauss[2][D + 1] = poww(D * (D - 1) / 2 % P , P - 2);
	for(int i = 0 ; i <= D ; ++i){
		int j = i;
		while(!gauss[j][i])
			++j;
		if(j != i)
			for(int k = i ; k <= D + 1 ; ++k)
				swap(gauss[i][k] , gauss[j][k]);
		int ny = poww(gauss[i][i] , P - 2);
		while(++j <= D)
			if(gauss[j][i]){
				int temp = ny * gauss[j][i] % P;
				for(int k = i ; k <= D + 1 ; ++k)
					gauss[j][k] = (gauss[j][k] - gauss[i][k] * temp % P + P) % P;
			}
	}
	for(int j = D ; j >= 0 ; --j){
		gauss[j][D + 1] = gauss[j][D + 1] * poww(gauss[j][j] , P - 2) % P;
		gauss[j][j] = 1;
		for(int k = j - 1 ; k >= 0 ; --k)
			if(gauss[k][j]){
				gauss[k][D + 1] = ((P - gauss[k][j]) * gauss[j][D + 1] + gauss[k][D + 1]) % P;
				gauss[k][j] = 0;
			}
	}
}

inline void multi(int x , int num){
	printf("+ %lld %lld %lld\n" , ze , x , mu - 1);
	printf("+ %lld %lld %lld\n" , ze , ze , mu);
	if(num & 1)
		printf("+ %lld %lld %lld\n" , mu - 1 , ze , mu);
	for(int i = 1 ; 1 << i <= num ; ++i){
		printf("+ %lld %lld %lld\n" , mu - i , mu - i , mu - i - 1);
		if(num & (1 << i))
			printf("+ %lld %lld %lld\n" , mu - i - 1 , mu , mu);
	}
}

inline void get2(int dir){
	printf("+ %lld %lld %lld\n" , ze , dir , pf + 1);
	printf("+ %lld %lld %lld\n" , ze , ze , pf);
	for(int i = 0 ; i <= D ; ++i){
		printf("^ %lld %lld\n" , pf + 1 , pf + 2);
		multi(pf + 2 , gauss[i][D + 1]);
		printf("+ %lld %lld %lld\n" , mu , pf , pf);
		printf("+ %lld %lld %lld\n" , pf + 1 , n1 , pf + 1);
	}
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	freopen("out" , "w" , stdout);
#endif
	D = read();
	P = read();
	init_0();
	init_gauss();
	printf("+ 1 2 3\n");
	get2(1);
	printf("+ %lld %lld 100\n" , pf , ze);
	get2(2);
	printf("+ %lld %lld 101\n" , pf , ze);
	get2(3);
	printf("+ %lld %lld 102\n" , pf , ze);
	multi(100 , P - 1);
	printf("+ %lld 102 102\n" , mu);
	multi(101 , P - 1);
	printf("+ %lld 102 102\n" , mu);
	multi(102 , poww(2 , P - 2));
	printf("f %lld" , mu);
	return 0;
}