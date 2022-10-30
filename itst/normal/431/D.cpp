#include<bits/stdc++.h>
using namespace std;

#define int long long

int M , K;

int binom(int P , int Q){
	if(P < Q) return 0;
	int tms = 1;
	for(int i = P ; i > P - Q ; --i) tms = tms * i / (P - i + 1);
	return tms;
}

int calc(int R , int id , int cnt){
	if(cnt > K) return 0;
	if(id == -1) return cnt == K;
	if(!(R >> id & 1)) return calc(R , id - 1 , cnt);
	return calc(R , id - 1 , cnt + 1) + binom(id , K - cnt);
}

signed main(){
	cin >> M >> K; int L = 1 , R = 1e18;
	while(L < R){int mid = (L + R) >> 1; calc(2 * mid , 63 , 0) - calc(mid , 63 , 0) >= M ? R = mid : L = mid + 1;}
	cout << R; return 0;
}