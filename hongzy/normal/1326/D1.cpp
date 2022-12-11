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
 
const int N = 4e6 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, f[N], ans, ansp, anss;
char t[N], s[N];
bool ok[N];
void solve() {
	scanf("%s", t + 1);
   n = strlen(t + 1); s[0] = '?'; s[1] = '%';
   ok[0] = 1;
   for(int i = 1; i <= n; i ++) ok[i] = ok[i - 1] && (t[i] == t[n - i + 1]);
	ans = 1; ansp = 1; anss = n + 1;
   for(int i = 1; i <= n; i ++) {
      s[i * 2] = t[i];
      s[i * 2 + 1] = '%';
   }
   int mid = 0, maxr = 0;
   for(int i = 1; i <= 2 * n + 1; i ++) {
      f[i] = i < maxr ? min(maxr - i, f[mid + mid - i]) : 1;
      for(; i + f[i] <= 2 * n + 1 && i - f[i] >= 1 && s[i + f[i]] == s[i - f[i]]; f[i] ++) ;
      if(i + f[i] > maxr) {
         maxr = i + f[i];
         mid = i;
      }
      int p1 = (i - f[i]) / 2, p2 = (i + f[i]) / 2;
      if(ok[min(p1, n - p2 + 1)]) {
      	if(ans < 2 * min(p1, n - p2 + 1) + f[i] - 1) {
//      		puts("YES");
      		ans = 2 * min(p1, n - p2 + 1) + f[i] - 1;
      		if(p1 <= n - p2 + 1) {
      			ansp = p1 + f[i] - 1; anss = n - p1 + 1;
				} else {
					ansp = n - p2 + 1; anss = p2 - f[i] + 1;
				}
			}
//			if(i % 2 == 0 && i / 2 == 5) {
//      		puts("<");
//			}
		}
   }
//   printf("ans = %d\n", ans);
   for(int i = 1; i <= ansp; i ++) putchar(t[i]);
   for(int i = anss; i <= n; i ++) putchar(t[i]);
   puts("");
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		solve();		
	}
	return 0;
}