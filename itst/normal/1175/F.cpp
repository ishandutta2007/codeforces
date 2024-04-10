#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

const int _ = 3e5 + 7;
#define int unsigned long long
int arr[_] , num[_] , sum[_] , Sum[_] , N;

signed main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i)
		cin >> arr[i];
	mt19937_64 rnd(time(0));
	for(int i = 1 ; i <= N ; ++i) Sum[i] = Sum[i - 1] ^ (num[i] = rnd());
	for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] ^ num[arr[i]];
	int cnt = 0 , Mx = 0;
	for(int i = 1 ; i <= N ; ++i) if(arr[i] == 1) --cnt;
	for(int i = 1 ; i <= N ; ++i)
		if(arr[i] == 1){
			Mx = 0;
			for(int j = i ; j <= N && (j == i || arr[j] != 1) ; ++j){
				Mx = max(Mx , arr[j]);
				cnt += Mx <= j && ((sum[j] ^ sum[j - Mx]) == Sum[Mx]);
			}
		}
	reverse(arr + 1 , arr + N + 1);
	for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] ^ num[arr[i]];
	for(int i = 1 ; i <= N ; ++i)
		if(arr[i] == 1){
			Mx = 0;
			for(int j = i ; j <= N && (j == i || arr[j] != 1) ; ++j){
				Mx = max(Mx , arr[j]);
				cnt += Mx <= j && ((sum[j] ^ sum[j - Mx]) == Sum[Mx]);
			}
		}
	cout << cnt;
	return 0;
}