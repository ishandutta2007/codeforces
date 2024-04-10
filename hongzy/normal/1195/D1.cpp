#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int mo = 998244353;
const int N = 1e5 + 10;

int n, a[N], pw[20];

int main() {
	scanf("%d", &n);
	pw[0] = 1;
	for(int i = 1; i < 20; i ++) pw[i] = pw[i - 1] * 10ll % mo;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		int y = 0;
		while(a[i]) {
			int x = a[i] % 10;
			ans = (ans + 1ll * x * pw[y] % mo * n % mo) % mo;
			ans = (ans + 1ll * x * pw[y + 1] % mo * n % mo) % mo;
			a[i] /= 10; y += 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}