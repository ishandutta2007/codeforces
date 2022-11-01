#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

long long cnt1[1 << 20] , mn[1 << 20] , times[1 << 20] , ans[1 << 20] , num[100007] , N , M;

void FWT_xor(long long* arr , int type){
	for(int i = 1 ; i < 1 << N ; i <<= 1)
		for(int j = 0 ; j < 1 << N ; j += (i << 1))
			for(int k = 0 ; k < i ; ++k){
				long long x = arr[j + k] , y = arr[i + j + k];
				arr[j + k] = x + y;
				arr[i + j + k] = x - y;
				if(type == -1){
					arr[j + k] >>= 1;
					arr[i + j + k] >>= 1;
				}
			}
}

inline char getc(){
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	return c;
}

int main(){
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			num[j] = (num[j] << 1) + getc() - 48;
	for(int i = 1 ; i <= M ; ++i)
		++times[num[i]];
	for(int i = 1 ; i < 1 << N ; ++i)
		cnt1[i] = cnt1[i - (i & -i)] + 1;
	for(int i = 1 ; i < 1 << N ; ++i)
		mn[i] = min(cnt1[i] , cnt1[((1 << N) - 1) ^ i]);
	FWT_xor(mn , 1);
	FWT_xor(times , 1);
	for(int i = 0 ; i < 1 << N ; ++i)
		ans[i] = mn[i] * times[i];
	FWT_xor(ans , -1);
	long long all = M * N;
	for(int i = 0 ; i < 1 << N ; ++i)
		all = min(all , ans[i]);
	cout << all;
	return 0;
}