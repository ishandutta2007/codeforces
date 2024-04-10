#include<bits/stdc++.h>
#define int long long
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

struct work{
	int a , b;
	bool operator <(const work k)const{
		return a > k.a || a == k.a && b < k.b;
	}
}now[101];
int dp[101][101] , N;

void input(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		now[i].a = read();
	for(int i = 1 ; i <= N ; ++i)
		now[i].b = read();
}

void init(){
	for(int i = 1 ; i <= N ; ++i)
		now[i].a *= 1000;
	sort(now + 1 , now + N + 1);
}

inline bool check(int mid){
	memset(dp , 0x3f , sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1 , pi ; i <= N ; i = pi + 1){
		pi = i;
		while(pi < N && now[pi + 1].a == now[i].a)
			++pi;
		int sum = 0;
		for(int j = i ; j <= pi ; ++j)
			sum += now[j].a - now[j].b * mid;
		for(int j = i - 1 ; j <= pi ; ++j , sum -= now[j].a - now[j].b * mid)
			for(int k = j - i + 1 ; k <= N && k - (j - i + 1) + (pi - i + 1 - (j - i + 1)) <= N ; ++k)
				dp[pi][k - (j - i + 1) + (pi - i + 1 - (j - i + 1))] = min(dp[pi][k - (j - i + 1) + (pi - i + 1 - (j - i + 1))] , dp[i - 1][k] + sum);
	}
	for(int i = 0 ; i <= N ; ++i)
		if(dp[N][i] <= 0)
			return 1;
	return 0;
}

void work(){
	int L = 1 , R = 1e12;
	while(L < R){
		int mid = (L + R) >> 1;
		check(mid) ? R = mid : L = mid + 1;
	}
	cout << L;
}

signed main(){
	input();
	init();
	work();
	return 0;
}