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

const int mod = 1000000007;
int a, b;

int main() {
	scanf("%d%d", &a, &b);
	int a1 = (1ll * (1 + a) * a / 2 % mod * b + a) % mod;
	int ans = 1ll * b * (b - 1) / 2 % mod * a1 % mod;
	printf("%d\n", ans);
	return 0;
}