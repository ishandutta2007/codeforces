#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	static long long arr[200003] , b[200003] , x[200003] , N;
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> b[i];
	for(int i = 1 ; i <= N ; ++i){arr[i] = b[i] + x[i]; x[i + 1] = max(x[i] , arr[i]); cout << arr[i] << ' ';}
	return 0;
}