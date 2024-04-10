#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
#define mod 1000000007
#define vi vector <int>
#define vpii vector <pii>
#define pii pair <int, int>
#define dbg(x) cerr << #x << " = " << x << endl
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
#define fio(fn) freopen(fn".in", "r", stdin), freopen(fn".out", "w", stdout)

#define N 1 << 20
#define linf 1e18

int tp;
ll stk[N];
int main() {
	int l; scanf("%d", &l);
	ll cur = 1;
	ll x = 0;
	while (l --) {
		char s[10]; scanf("%s", s);
		if (s[0] == 'a') {
			x += cur;
			if (x >= linf) x = linf;
		} else if (s[0] == 'e') {
			-- tp;
			cur = stk[tp];
		} else {
			int n; scanf("%d", &n);
			stk[tp ++] = cur;
			if (cur >= linf / n) cur = linf;
			else cur *= n;
			if (cur >= linf) cur = linf;
		}
	}
	if (x >= (1LL << 32)) puts("OVERFLOW!!!");
	else printf("%lld\n", x);
	return 0;
}