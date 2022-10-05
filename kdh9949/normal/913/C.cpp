#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using pll = pair<ll, ll>;

#define X first
#define Y second

const int MN = 31;

int n, m;
ll a[MN], ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	if(m & 1) ans = a[0];
	for(int i = 1; i < MN; i++){
		if(a[i]) a[i] = min(a[i], 2 * a[i - 1]);
		else a[i] = 2 * a[i - 1];
		if(m & (1 << i)) ans = min(ans + a[i], 2 * a[i]);
		else ans = min(ans, a[i]);
	}
	printf("%lld\n", ans);
}