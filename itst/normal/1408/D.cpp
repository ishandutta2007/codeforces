#include<bits/stdc++.h>
using namespace std;

int p[2003][2] , q[2003][2];

int main(){
	ios::sync_with_stdio(0);
	int N , M; cin >> N >> M;
	for(int i = 1 ; i <=N ; ++i) cin >> p[i][0] >> p[i][1];
	for(int j = 1 ; j <= M ; ++j) cin >> q[j][0] >> q[j][1];
	static int mx[1000003];
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(p[i][0] <= q[j][0] && p[i][1] <= q[j][1]) mx[q[j][0] - p[i][0]] = max(mx[q[j][0] - p[i][0]] , q[j][1] - p[i][1] + 1);
	int ans = 1e9;
	for(int i = 1e6 ; ~i ; --i){
		mx[i] = max(mx[i] , mx[i + 1]); ans = min(ans , i + mx[i]);
	}
	cout << ans; return 0;
}