#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
using ld = long double;
array<ld, 2> eq(ld b, ld c) {
	ld D = b*b - 4*c;
	return {(-b - sqrt(D))/2., (-b + sqrt(D))/2.};
}
ld mn[maxn], mx[maxn], xs[maxn], _a[maxn], _b[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	xs[0] = 0;
	for(int i = 1; i <= n; i++) cin >> mx[i], xs[i] = xs[i-1] + mx[i];
	for(int j = 1; j <= n; j++) cin >> mn[j];
	ld As = 0, Bs = 0;
	for(int i = 1; i <= n; i++) {
		ld sm = mn[i] + mx[i];//(As+x)(Bs+sm-x) = xs[i]
		_a[i] = 0.5 * (sqrt( As*As + Bs*Bs + 2*As*Bs + (2*As + 2*Bs)*sm + sm*sm - 4*xs[i] + 1e-18) - As + Bs + sm);
		_b[i] = sm - _a[i];
		As += _a[i];
		Bs += _b[i];
	}
	cout << fixed << setprecision(15);
	for(int i = 1; i <= n; i++) cout << _a[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << _b[i] << " "; cout << endl;
}