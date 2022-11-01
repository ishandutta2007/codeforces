#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000003;

ll mat[65][105][105], vec[105];
ll c; int w, h;

void mult(ll a[105][105])
{
	ll d[105] = {};
	for (int i = 0;i < w;i++) for (int j = 0;j < w;j++)
		d[i] = (d[i]+a[i][j]*vec[j])%MOD;
	for (int i = 0;i < w;i++) vec[i] = d[i];
}

void mult(ll d[105][105], ll a[105][105])
{
	for (int i = 0;i < w;i++) for (int j = 0;j < w;j++) for (int k = 0;k < w;k++)
		d[i][j] = (d[i][j]+a[i][k]*a[k][j])%MOD;
}

int main()
{
	cin >> c >> w >> h; w++;
	for (int i = 0;i < w;i++) mat[0][0][i] = 1;
	for (int i = 1;i < w;i++) mat[0][i][i-1] = h;
	for (int i = 1;i < 62;i++) mult(mat[i], mat[i-1]);
	vec[0] = 1;
	for (int i = 0;i < 62;i++) if (c&(1ll<<i)) mult(mat[i]);
	ll ans = 0;
	for (int i = 0;i < w;i++) ans = (ans+vec[i])%MOD;
	cout << ans << endl;
	return 0;
}