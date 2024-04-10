#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 1e5 + 7;
int N , Q , arr[MAXN] , delta[MAXN] , sum[MAXN];

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		arr[i] = read();
	sort(arr + 1 , arr + N + 1);
	for(int i = 1 ; i < N ; ++i)
		delta[i] = arr[i + 1] - arr[i];
	sort(delta + 1 , delta + N);
	for(int i = 1 ; i < N ; ++i)
		sum[i] = sum[i - 1] + delta[i];
	Q = read();
	while(Q--){
		int l = read() , r = read() , del = r - l + 1;
		int t = upper_bound(delta + 1 , delta + N , del) - delta - 1;
		printf("%lld " , sum[t] + (N - t) * del);
	}
	return 0;
}