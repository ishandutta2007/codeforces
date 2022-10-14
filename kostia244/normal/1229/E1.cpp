#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<21, mod = 1e9 + 7, i100 = 570000004;
int n, p[6][6], dp[1<<20], id[6][6][6], good[1<<20], m2n[1<<6], n2m[1<<6];
void enumerate() {
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			for(int k = j+1; k < n; k++) {
				//cout << cnt << ": " << i << " " << j << ' ' << k << '\n';
				n2m[cnt] = (1<<i)|(1<<j)|(1<<k);
				m2n[(1<<i)|(1<<j)|(1<<k)] = cnt;
				id[i][j][k] = id[i][k][j] = id[j][i][k] = id[j][k][i] = id[k][i][j] = id[k][j][i] = cnt++;
			}
	for(int msk = 0; msk < 1<<20; msk++) {
		int comp = 0;
		for(int i = 0; i < 20; i++) {
			if(!((msk>>i)&1)) continue;
			comp |= 1<<m2n[((1<<6)-1)^n2m[i]];
		}
		good[msk] = comp;
	}
	for(int i = 0; i < 1<<20; i++) assert(good[good[i]] == i);
}
#define has(msk, x) (((msk)>>(x))&1)
void calc(int x) {
	int msk = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if(i!=j&&i!=k&&j!=k&&has(x, i)&&has(x, 6+j)&&has(x, 12+k)) msk |= 1<<id[i][j][k];
	int prob = 1;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < n; j++)
			if(has(x, i*6 + j)) prob = prob*1ll*p[i][j]%mod;
			else prob = prob*1ll*(mod+1-p[i][j])%mod;
	//if(prob)
	//	cout << bitset<18>(x) << ' ' << msk << " " << prob << "::1\n";
	dp[msk] = (dp[msk]+prob)%mod;
}
ll ans = 0;
void add(int x) {
	int msk = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if(i!=j&&i!=k&&j!=k&&has(x, i)&&has(x, 6+j)&&has(x, 12+k)) {
					//if(x == 132104) cout << i << " " << j << " " << k << '\n';
					msk |= 1<<id[i][j][k];
				}
	int prob = 1;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < n; j++)
			if(has(x, i*6 + j)) prob = prob*1ll*p[3+i][j]%mod;
			else prob = prob*1ll*(mod+1-p[3+i][j])%mod;
	//if(prob)
	//	cout << x << ' ' << msk << " " << prob << " " << good[msk] << "::2\n";
	//if(!msk) return;
	int p2 = (mod + dp[(1<<20)-1] - dp[((1<<20)-1)^good[msk]])%mod;
	ans = (ans + prob*1ll*p2)%mod;
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> p[i][j], p[i][j] = p[i][j]*1ll*i100%mod;
	for(int i = n; i < 6; i++)
			p[i][i] = 1;
	n = 6;
	enumerate();
	for(int i = 0; i < 1<<18; i++) calc(i);
	for(int i = 0;i < 20; ++i) for(int mask = 0; mask < (1<<20); ++mask){
	if(mask & (1<<i))
		(dp[mask] += dp[mask^(1<<i)])%=mod;}
	for(int i = 0; i < 1<<18; i++) add(i);
	cout << ans;
}