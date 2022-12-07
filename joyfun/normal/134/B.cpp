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

const int inf = 0x3f3f3f3f;

int n;

int g(int a, int b) {
	if (b == 0) return -1;
	return a / b + g(b, a % b);
}

int main() {
	scanf("%d", &n);
	int ans = inf;
	for (int i = 1; i <= n; i++) if (__gcd(i, n) == 1) ans = min(ans, g(n, i));
	printf("%d\n", ans);
	return 0;
}