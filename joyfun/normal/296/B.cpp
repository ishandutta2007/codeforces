#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
const int mod = 1e9+7;

int n;
char a[N], b[N];

int main() {
	scanf("%d", &n);
	scanf("%s%s", a + 1, b + 1);
	int tot = 1, l = 1, r = 1, m = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '?' && b[i] == '?') {
			tot = 1ll * tot * 100 % mod;
			l = 1ll * l * 55 % mod;
			r = 1ll * r * 55 % mod;
			m = 1ll * m * 10 % mod;
		} else if (a[i] == '?') {
			tot = 1ll * tot * 10 % mod;
			l = 1ll * l * (b[i] - '0' + 1) % mod;
			r = 1ll * r * (10 - (b[i] - '0')) % mod;
		} else if (b[i] == '?') {
			tot = 1ll * tot * 10 % mod;
			l = 1ll * l * (10 - (a[i] - '0')) % mod;
			r = 1ll * r * (a[i] - '0' + 1) % mod;
		} else {
			if (a[i] < b[i]) r = 0, m = 0;
			if (a[i] > b[i]) l = 0, m = 0;
		}
	}
	printf("%d\n", (int)((1ll * tot - l - r + m) % mod + mod) % mod);
	return 0;
}