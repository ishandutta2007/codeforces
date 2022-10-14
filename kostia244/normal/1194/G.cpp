#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 102, mod = (119 << 23) + 1;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int dp[maxn][10][10][2][2][1 << 4][1 << 4], g1[10], g2[10], tsz;
string n;
int count(int x, int y) {
	memset(dp, 0, sizeof dp);
	dp[0][0][0][1][1][0][0] = 1;
	int t;
	for (int i = 0; i < n.size(); i++) {
		for (int rem1 = 0; rem1 < 10; rem1++) {
			for (int rem2 = 0; rem2 < 10; rem2++) {
				for (int d1 = 0; d1 < 2; d1++) {
					for (int d2 = 0; d2 < 2; d2++) {
						for (int msk1 = 0; msk1 < 1 << tsz; msk1++) {
							for (int msk2 = 0; msk2 < 1 << tsz; msk2++) {
								int cur = dp[i][rem1][rem2][d1][d2][msk1][msk2];
								if (!cur)
									continue;
//								cout << i << " " << rem1 << " " << rem2 << " " << d1 << " " << d2 << " " << msk1 << " " << msk2 << " " << cur << "\n";
								for (int dig = 0; dig < 10; dig++) {
									t = rem1 + dig * x;
									int nrem1 = t / 10, ndig1 = t % 10, nd1 =
											(ndig1 == (n[i] - '0')) ? d1 : (ndig1 < (n[i] - '0'));
									t = rem2 + dig * y;
									int nrem2 = t / 10, ndig2 = t % 10, nd2 =
											(ndig2 == (n[i] - '0')) ? d2 : (ndig2 < (n[i] - '0'));
									int nmsk1 = msk1 | (g1[ndig1]!=-1)*(1 << g1[ndig1]);
									int nmsk2 = msk2 | (g2[ndig2]!=-1)*(1 << g2[ndig2]);
//									cout << ndig1 << " " <<ndig2 << " " << nd1 << " " << nd2 << "\n";
									dp[i + 1][nrem1][nrem2][nd1][nd2][nmsk1][nmsk2] += cur;
									if(dp[i + 1][nrem1][nrem2][nd1][nd2][nmsk1][nmsk2]>=mod)
										dp[i + 1][nrem1][nrem2][nd1][nd2][nmsk1][nmsk2]-=mod;
								}
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int msk1 = 0; msk1 < 1 << tsz; msk1++) {
		for (int msk2 = 0; msk2 < 1 << tsz; msk2++) {
			if (msk1 & msk2)
				ans += dp[n.size()][0][0][1][1][msk1][msk2];
			if (ans >= mod)
				ans -= mod;
		}
	}
	return ans;
}
map<pair<int, int>, vector<pi>> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
	cin >> n;
	reverse(all(n));
	for (int i = 1; i < 10; i++)
		for (int j = i+1; j < 10; j++) {
			int t = __gcd(i, j);
			mp[ { i / t, j / t }].pb( { i, j });
		}
	for (auto i : mp) {
		memset(g1, -1, sizeof g1);
		memset(g2, -1, sizeof g2);
		int c = 0;
		tsz = i.second.size();
//		cout << i.first.first << "/" <<i.first.second << ":\n";
		for (auto j : i.second) {
//			cout << j.first << "/" <<j.second << "\n";
			g1[j.first] = c;
			g2[j.second] = c++;
		}
//		cout << tsz << "\n";
		ans += count(i.first.first, i.first.second);
		if (ans >= mod)
			ans -= mod;
//		cout << ans << "\n";
	}
	ans = (ans<<1)%mod;
	ll t = 1;
	for(int i = 0; i < n.size(); i++) ans = (ans + t*(n[i]-'0'))%mod, t = (t*10)%mod;
	cout << ans << "\n";
}