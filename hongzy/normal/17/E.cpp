#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 4e6 + 10;
const int mo = 51123987;
const int inv2 = (mo + 1) / 2;
char t[N / 2], s[N];
int n, f[N], c[N], p[N], p2[N], tot;
int main() {
	scanf("%d%s", &n, t + 1); s[0] = '?'; s[1] = '#';
	for(int i = 1; i <= n; i ++) {
		s[i * 2] = t[i]; s[i * 2 + 1] = '#';
	}
	n = 2 * n + 1;
	int mid = 0, maxr = 0;
	for(int i = 1; i <= n; i ++) {
		f[i] = i < maxr ? min(maxr - i, f[2 * mid - i]) : 1;
		while(s[i + f[i]] == s[i - f[i]]) f[i] ++;
		if(i + f[i] > maxr) { maxr = i + f[i]; mid = i; }
		(tot += f[i] / 2) %= mo;
	}
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '#') c[i + 1] ++, c[i + f[i]] --;
		else c[i] ++, c[i + f[i]] --; 
	}
	for(int i = 2; i <= n; i += 2) {
		c[i] += c[i - 2]; p[i] = c[i];
	}
	for(int i = 2; i <= n; i += 2) {
		(p[i] += p[i - 2]) %= mo; p2[i] = (p2[i - 2] + p[i]) % mo;
	}
	int ans = 0;
	for(int i = 3; i <= n; i ++) {
		if(s[i] == '#') (ans += p2[i - 3] - (i - f[i] < 2 ? 0 : p2[i - f[i] - 2])) %= mo;
		else (ans += p2[i - 2] - (i - f[i] < 2 ? 0 : p2[i - f[i] - 2])) %= mo;
	}
	ans = (tot * (tot - 1ll) % mo * inv2 % mo - ans) % mo;
	printf("%d\n", (ans % mo + mo) % mo);
	return 0;
}