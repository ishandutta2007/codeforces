#include<bits/stdc++.h>
#define int long long
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

const int MAXN = 2e5 + 10;
int ans[MAXN] , num1[MAXN] , num2[MAXN] , sum , N;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		sum += (num1[i] = read());
	for(int i = 1 ; i <= N ; ++i)
		sum += (num2[i] = read());
	if(sum % (2 * N)){
		puts("-1");
		return 0;
	}
	sum /= N * 2;
	for(int i = 1 ; i <= N ; ++i){
		ans[i] = num1[i] + num2[i] - sum;
		if(ans[i] % N){
			puts("-1");
			return 0;
		}
		ans[i] /= N;
	}
	for(int i = 0 ; i <= 30 ; ++i){
		int cnt = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(ans[j] & (1 << i)){
				++cnt;
				num2[j] -= N * (1 << i);
			}
		for(int j = 1 ; j <= N ; ++j)
			if(ans[j] & (1 << i))
				num1[j] -= cnt * (1 << i);
			else
				num2[j] -= cnt * (1 << i);
	}
	for(int i = 1 ; i <= N ; ++i)
		if(num1[i] || num2[i]){
			puts("-1");
			return 0;
		}
	for(int i = 1 ; i <= N ; ++i)
		cout << ans[i] << ' ';
	return 0;
}