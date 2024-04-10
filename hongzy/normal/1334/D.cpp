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
 
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int T, n, len, seq[N];
ll l, r;
void getseq(int u) {
	for(int i = u + 1; i <= n; i ++) {
		seq[++ len] = u;
		seq[++ len] = i;
	}
}
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d%lld%lld", &n, &l, &r);
		bool tag = 0;
		if(r == n * (n - 1ll) + 1) {
			r --; tag = 1;
		}
		ll sum = 0, pre = 0; len = 0;
		for(int i = 1; i <= n; i ++) {
			if(r <= sum) break ;
			sum += 2 * (n - i);
			if(sum >= l) {
				getseq(i);	
			} else {
				pre += 2 * (n - i);
			}
		}
		l -= pre; r -= pre;
		for(int i = l; i <= r; i ++)
			printf("%d ", seq[i]);
		if(tag) printf("1 "); 
		puts("");
	}
	return 0;
}