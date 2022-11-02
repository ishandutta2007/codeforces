#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int n, cnt[11][62][62], dt[62][62][62];
ll ans;

int convert (char T) {
	if('0' <= T && T <= '9') return T - '0';
	if('A' <= T && T <= 'Z') return T - 'A' + 10;
	return T - 'a' + 36;
}

map<string, bool> chk;

ll solve (int i, int j, int k, int l) {
	return 1ll * dt[i][j][k] * dt[i][j][l] % mod * dt[i][k][l] % mod * dt[j][k][l] % mod;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		string tmp;
		cin >> tmp;
		int L = tmp.size(), A = convert(tmp[0]), B = convert(tmp.back());
		if(!chk[tmp]) {
			chk[tmp] = 1;
			cnt[L][A][B]++;
		}
		reverse(tmp.begin(), tmp.end());
		if(!chk[tmp]) {
			chk[tmp] = 1;
			cnt[L][B][A]++;
		}
	}
	for(int x=3;x<=10;x++) {
		for(int i=0;i<62;i++) {
			for(int j=i;j<62;j++) {
				for(int k=j;k<62;k++) {
					dt[i][j][k] = 0;
					for(int t=0;t<62;t++) {
						dt[i][j][k] += 1ll * cnt[x][i][t] * cnt[x][j][t] % mod * cnt[x][k][t] % mod;
						dt[i][j][k] %= mod;
					}
					dt[k][i][j] = dt[k][j][i] = dt[j][i][k] = dt[j][k][i] = dt[i][k][j] = dt[i][j][k];
				}
			}
		}
		for(int i=0;i<62;i++) {
			ans += 1 * solve(i, i, i, i);
			for(int j=i+1;j<62;j++) {
				ans += 4ll * solve(i, i, i, j) + 6ll * solve(i, i, j, j) + 4ll * solve(i, j, j, j);
				for(int k=j+1;k<62;k++) {
					ans += 12ll * solve(i, i, j, k) + 12ll * solve(j, j, i, k) + 12ll * solve(k, k, i, j);
					for(int l=k+1;l<62;l++) {
						ans += 24ll * solve(i, j, k, l);
					}
				}
			}
		}
		ans %= mod;
	}
	printf("%lld\n", ans);
}