#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
const int mod = 1e9 + 7;
int mat[1010][1010], ans = 0;
int n, m;
bitset<1010> msk[1010];
inline bool can(int z) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			msk[i][j] = mat[i][j] >= z;
		}
	}
	for (int i = 0; i < n; i++) {
		if(msk[i].count()<2) continue;
		for (int j = i+1; j < n; j++)
			if ((msk[i] & msk[j]).count() > 1)
				return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	int ans = 0;
	for (int i = 1 << 29; i;i>>=1) {
		if (can(ans + i))
			ans += i;
	}
	cout << ans;
}