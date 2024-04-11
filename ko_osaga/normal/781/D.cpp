#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<string, lint> pi;
const int mod = 1e9 + 7;

struct mat{
	bool a[505][505];
}dp[61][2];

int n, m;

mat merge(mat &p, mat &q){
	mat r;
	memset(r.a, 0, sizeof(r.a));
	bitset<500> bs1[505], bs2[505];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(p.a[i][j]) bs1[i].set(j);
			if(q.a[j][i]) bs2[i].set(j);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((bs1[i] & bs2[j]).any()){
				r.a[i][j] = 1;
			}
		}
	}
	return r;
}

bool hpath(mat &p){
	for(int i=0; i<n; i++) if(p.a[0][i]) return 1;
	return 0;
}

int main(){
	cin >> n >> m;
	while(m--){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		dp[0][x].a[s-1][e-1] = 1;
	}
	for(int i=1; i<=60; i++){
		dp[i][0] = merge(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = merge(dp[i-1][1], dp[i-1][0]);
	}
	mat ret;
	memset(ret.a, 0, sizeof(ret.a));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) ret.a[i][j] = 1;
	}
	lint ans = 0;
	int cur = 0;
	for(int i=60; i>=0; i--){
		auto l = merge(ret, dp[i][cur]);
		if(hpath(l)) ret = l, ans += (1ll << i), cur ^= 1;
	}
	if(ans > 1000000ll * 1000000ll * 1000000ll){
		ans = -1;
	}
	cout << ans;
}