#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, L[2][N], R[2][N];
char s[N];
ll ans, res, x, y;
int main() {
	scanf("%s%lld%lld", s + 1, &x, &y);
	n = strlen(s + 1);
	rep(i, 1, n) s[i] -= '0';
	rep(i, 0, 1) rep(j, 1, n) L[i][j] = L[i][j - 1] + (s[j] == i);
	rep(i, 0, 1) per(j, n, 1) R[i][j] = R[i][j + 1] + (s[j] == i);
	ll cur = 0, all = 0;
	rep(i, 1, n) if(s[i] ^ 15) {
		if(s[i] == 0) ans += y * L[1][i - 1];
		if(s[i] == 1) ans += x * L[0][i - 1];
	} else {
		all ++;
		if(x <= y) { //0000011111
			cur += x * L[0][i - 1] + y * R[0][i + 1];
		} else {
			cur += y * L[1][i - 1] + x * R[1][i + 1];
		}
	}
	res = cur;
	int c = 0;
	rep(i, 1, n) if(s[i] == 15) {
		c ++;
		if(x <= y) {
			cur -= x * L[0][i - 1] + y * R[0][i + 1];
			cur += y * L[1][i - 1] + x * R[1][i + 1];
		} else {
			cur -= y * L[1][i - 1] + x * R[1][i + 1];
			cur += x * L[0][i - 1] + y * R[0][i + 1];
		}
		res = min(res, cur + (x <= y ? x : y) * c * (all - c));
	}
	printf("%lld\n", ans + res);
	return 0;
}