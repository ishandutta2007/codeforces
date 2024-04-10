#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
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
#define int long long
const int MAXN = 3e5 + 7;
int hei[MAXN] , tmp[MAXN] , N , H;
signed main(){
	N = read(); H = read();
	for(int i = 1 ; i <= N ; ++i)
		hei[i] = read();
	int L = 0 , R = N;
	while(L < R){
		int mid = ((L + R + 1) >> 1);
		memcpy(tmp , hei , sizeof(int) * (N + 1));
		sort(tmp + 1 , tmp + mid + 1);
		int cur = 0 , sum = 0;
		for(int i = mid ; i ; --i)
			if(cur){
				sum += cur;
				cur = 0;
			}
			else cur = tmp[i];
		sum + cur <= H ? L = mid : R = mid - 1;
	}
	cout << R;
	return 0;
}