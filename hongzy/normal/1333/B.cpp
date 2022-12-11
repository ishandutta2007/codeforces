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
int n, a[N], b[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", a + i);
		for(int i = 1; i <= n; i ++) scanf("%d", b + i);
		static bool big[N], small[N]; bool tag = 1;
		bool bg = 0, sm = 0;
		for(int i = 1; i <= n; i ++) {
			big[i] = bg; small[i] = sm;
			if(a[i] > 0) bg = 1;
			if(a[i] < 0) sm = 1;
		}
		for(int i = 1; i <= n; i ++) {
			if(a[i] < b[i] && !big[i]) tag = 0;
			if(a[i] > b[i] && !small[i]) tag = 0;
		}
		puts(tag ? "YES" : "NO");
	}
	return 0;
}