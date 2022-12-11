#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;

#define fir puts("sjfnb")
#define sec puts("cslnb")

ll n, a[100010];

int main() {
	scanf("%I64d", &n);
	for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	bool z = 1;
	for(int i = 1; i <= n; i ++) if(a[i]) z = 0;
	if(z) {
		sec;
		return 0;
	}
	sort(a + 1, a + n + 1); int cnt = 0;
	if(n >= 2 && !a[1] && !a[2]) {
		sec; return 0;
	}
	if(a[1] == a[2]) cnt ++;
	for(int i = 3; i <= n; i ++)
		if(a[i] == a[i - 1]) {
			cnt ++;
			if(a[i - 2] + 1 == a[i]) {
				sec; return 0;
			}
		}
	for(int i = 1; i <= n - 2; i ++) {
		if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			sec; return 0;
		}
	}
	if(cnt >= 2) {
		sec; return 0;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++) ans += a[i] - (i - 1);
	if(ans & 1) fir;
	else sec;
	return 0;
}