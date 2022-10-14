#pragma GCC optimize("inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = unsigned long long;
ll dp[2][2520][1<<6][2],  mp[1<<6][10], x[20];
inline int go(int msk, int d) {
	if(mp[msk][d]!=-1) return mp[msk][d];
	int omsk = msk;
	if(d>1&&!(d&1)&&(msk&3)==0)
		++msk;
	if((d==4||d==8)&&(msk&3)==1)
		++msk;
	if(d==8)
		msk|=3;
	if(d>1&&(d&1)) {
		msk|=(1<<(1+(d>>1)));
	}
	if(d==6)
		msk|=4;
	return mp[omsk][d]=msk;
}
int cnt = 0;
inline ll solve(ll _x) {
	if(!_x) return 1;
	memset(dp, 0, sizeof dp);
	string tx = to_string(_x);
	reverse(all(tx));
	for(int i = 0; i < tx.size(); i++) x[i] = tx[i]-'0';
//	cout << x << "\n";
	dp[0][0][0][0] = 1;
	for(int pw = 1, it = 0; it < tx.size(); it++, pw = (pw*10)%2520) {
		int i = it&1;
		memset(dp[i^1], 0, sizeof dp[i^1]);
		for(int sm = 0; sm < 2520; sm++) {
			for(int msk = 0; msk < 1 << 6; msk++) {
				for(int r = 0; r < 2; r++) {
					if(!dp[i][sm][msk][r]) continue;
					for(int d = 0; d <= 9; d++) {
						cnt++;
						dp[i^1][(sm+d*pw)%2520][mp[msk][d]][d==x[it]?r:d>x[it]] += dp[i][sm][msk][r];
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int rem = 0; rem < 2520; rem++) {
		for(int ok, msk = 0; msk < 1<<6; msk++) {
			ok = rem%(int)pow(2, msk&3)==0;
			for(int i = 2; i < 6; i++) if((msk>>i)&1) ok &= rem%(2*(i-1)+1)==0;
			if(ok) ans += dp[tx.size()&1][rem][msk][0];
// 			if(ok&&rem<100) cout << rem << " " << msk << "\n";
		}
	}
	return ans;//
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(mp, -1, sizeof mp);
	for(int i = 0; i < 1<<6; i++)
	for(int j = 0; j < 10; j++)
	go(i, j);
	ll t,l,r;
	cin >> t;
	while(t--) cin >> l >> r, cout << solve(r)-solve(l-1) << '\n';
// 	cout << cnt << "\n";
}