#include <bits/stdc++.h>
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
int T, n, a[N], b[N];
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n);
		bool tag = 1;
		for(int i = 1; i <= n; i ++) {
			scanf("%d%d", a + i, b + i);
			tag &= a[i] >= b[i];
			if(i > 1) {
				tag &= a[i] >= a[i - 1];
				tag &= b[i] >= b[i - 1];
				tag &= a[i] - a[i - 1] >= b[i] - b[i - 1];
			}
		}
		puts(tag ? "YES" : "NO");
	}
	return 0;
}