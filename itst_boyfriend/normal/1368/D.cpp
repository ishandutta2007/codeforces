#include<bits/stdc++.h>
using namespace std;

int N , cnt[21];

int main(){
	ios::sync_with_stdio(0);
	cin >> N; for(int i = 1 ; i <= N ; ++i){int A; cin >> A; for(int j = 0 ; j < 20 ; ++j) cnt[j] += A >> j & 1;}
	long long sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		int val = 0; for(int j = 0 ; j < 20 ; ++j) if(cnt[j]){val |= 1 << j; --cnt[j];}
		sum = sum + 1ll * val * val;
	}
	cout << sum; return 0;
}