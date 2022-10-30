#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 3e5 + 7;
int N , K , sum[_];

signed main(){
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){
		cin >> sum[i]; sum[i] += sum[i - 1];
	}
	int all = sum[N] * K;
	sort(sum + 1 , sum + N);
	for(int i = 1 ; i < K ; ++i) all -= sum[i];
	cout << all;
	return 0;
}