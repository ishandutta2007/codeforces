#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 6e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> ran(0, 1ll << 62);
int n, a[7], df;
pair<int, int> b[N];
int ans = 2e9;
int use[N];
int main() {
	rep(i, 1, 6) scanf("%d", a + i);
	scanf("%d", &n); int c = 0;
	rep(i, 1, n) {
		int x; scanf("%d", &x);
		rep(j, 1, 6) b[++ c] = pii(x - a[j], i);
	}
	sort(b + 1, b + c + 1);
	int r = 0;
	rep(i, 1, c) {
		while(df < n) {
			if(r == c) break ;
			r ++;
			if(!use[ b[r].sc ] ++) {
				df ++;
			}
		}
		//printf("df = %d\n", df);
		if(df == n) {
			ans = min(ans, b[r].fs - b[i].fs);
			if(-- use[ b[i].sc ] == 0) {
				df --;
			}	
		} else break ;
	}
	printf("%d\n", ans);
   return 0;
}