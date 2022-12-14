#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<random>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

char Map[1003][1003];
int N , M;
unsigned int line[1003][1003] , sum[1003][1003] , num[26];

unsigned int query(int x1 , int y1 , int x2 , int y2){
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	#endif
	mt19937 rnd(time(0));
	for(int i = 0 ; i < 26 ; ++i)
		num[i] = rnd();
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			char c; cin >> c; Map[i][j] = c;
			line[i][j] = line[i - 1][j] + num[c - 'a'];
		}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			sum[i][j] = sum[i][j - 1] + line[i][j];
	long long sum = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			int L = i , R = N;
			while(L < R){
				int mid = (L + R + 1) >> 1;
				line[mid][j] - line[i - 1][j] == (mid - i + 1) * num[Map[i][j] - 'a'] ? L = mid : R = mid - 1;
			}
			if(i + 3 * (L - i + 1) - 1 > N) continue;
			int i1 = L + 1 , L1 = i1 + L - i , i2 = L1 + 1 , L2 = i2 + L - i;
			if(line[L1][j] - line[i1 - 1][j] != num[Map[i1][j] - 'a'] * (L - i + 1)) continue;
			if(line[L2][j] - line[i2 - 1][j] != num[Map[i2][j] - 'a'] * (L - i + 1)) continue;
			if(Map[i][j] == Map[i1][j] || Map[i1][j] == Map[i2][j]) continue;
			int l = j , r = M;
			while(l < r){
				int mid = (l + r + 1) >> 1;
				if(query(i , j , L , mid) != num[Map[i][j] - 'a'] * (L - i + 1) * (mid - j + 1)
			|| query(i1 , j , L1 , mid) != num[Map[i1][j] - 'a'] * (L1 - i1 + 1) * (mid - j + 1)
			|| query(i2 , j , L2 , mid) != num[Map[i2][j] - 'a'] * (L2 - i2 + 1) * (mid - j + 1)
				) r = mid - 1;
				else l = mid;
			}
			sum += l - j + 1;
		}
	cout << sum;
	return 0;
}