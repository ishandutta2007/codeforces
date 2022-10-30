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

const int MAXN = 200000;
int N , K , times[MAXN + 10];

bool check(int mid){
	int cnt = 0;
	for(int i = 1 ; i <= MAXN && cnt < K ; ++i)
		cnt += times[i] / mid;
	return cnt >= K;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("1077D.in" , "r" , stdin);
	//freopen("1077D.out" , "w" , stdout);
#endif
	N = read();
	K = read();
	for(int i = 1 ; i <= N ; ++i)
		++times[read()];
	int l = 1 , r = N / K;
	while(l < r){
		int mid = l + r + 1 >> 1;
		check(mid) ? l = mid : r = mid - 1;
	}
	for(int i = 1 ; i <= MAXN ; ++i)
		for(int j = 1 ; j <= times[i] / l && K ; ++j){
			--K;
			printf("%d " , i);
		}
	return 0;
}