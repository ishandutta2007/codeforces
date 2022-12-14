#include<bits/stdc++.h>
using namespace std;

int x[6003] , y[6003] , N; long long cnt[2][2];

int main(){
	ios::sync_with_stdio(0);
	cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> x[i] >> y[i]; ++cnt[x[i] / 2 % 2][y[i] / 2 % 2];}
	long long ans = 0;
	for(int i = 0 ; i < 2 ; ++i)
		for(int j = 0 ; j < 2 ; ++j)
			ans += cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6 + (cnt[i][j] - 1) * (cnt[i][j]) * (N - cnt[i][j]) / 2;
	cout << ans; return 0;
}