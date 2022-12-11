#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}

int n, b[N];
ll cnt[N * 10];
int main() {
	scanf("%d", &n); ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", b + i);
		cnt[b[i] - i + N] += b[i];
		ans = max(ans, cnt[b[i] - i + N]);
	}
	printf("%lld\n", ans);
	return 0;
}