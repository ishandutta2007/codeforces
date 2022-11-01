#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7;
long long val[_] , mrk[_] , N , sum;

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> val[i] >> mrk[i]; sum += val[i];}
	if(sum < 0) for(int i = 1 ; i <= N ; ++i) val[i] = -val[i];
	long long ans = 0;
	for(int i = 0 ; i < 62 ; ++i){
		long long tsum = 0;
		for(int j = 1 ; j <= N ; ++j) if(mrk[j] < (1ll << (i + 1))){tsum += val[j]; val[j] = 0;}
		if(tsum > 0){ans |= 1ll << i; for(int j = 1 ; j <= N ; ++j) if(mrk[j] >> i & 1) val[j] = -val[j];}
	}
	cout << ans; return 0;
}