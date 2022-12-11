#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int n, m, f[N], g[N];
char s[110][110];
bool same(int u, int v) {
	for(int i = 1; i <= m; i ++)
		if(s[u][i] != s[v][i]) return 0;
	return 1; 
}
bool rev(int u, int v) {
	for(int i = 1; i <= m; i ++)
		if(s[u][i] != s[v][m - i + 1]) return 0;
	return 1; 
}
void print(int u) {
	printf("%s", s[u] + 1);
}
void pf(int u) {
	for(int i = m; i >= 1; i --) putchar(s[u][i]);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		bool t = 0;
		for(int j = 1; j < i; j ++) {
			if(same(i, j)) { f[j] ++; t = 1; break ; }
			if(rev(i, j)) { g[j] ++; t = 1; break ; }
		}
		if(t) { i --; n --; continue ; }
		f[i] = 1;
	}
	int len = 0, mid = 0, midx;
	vector<int> ans;
	for(int i = 1; i <= n; i ++) {
		if(rev(i, i)) {
			len += 2 * m * (f[i] / 2);
			for(int j = f[i] / 2; j >= 1; j --)
				ans.push_back(i);
			if(f[i] % 2 == 1) { mid = 1; midx = i; }
		} else {
			for(int j = min(f[i], g[i]); j >= 1; j --)
				ans.push_back(i);
			len += 2 * m * min(f[i], g[i]); 
		}
	}
	printf("%d\n", len + mid * m);
	for(int i = 0; i < (int) ans.size(); i ++) print(ans[i]);
	if(mid) print(midx);
	for(int i = (int) ans.size() - 1; i >= 0; i --) pf(ans[i]);
	return 0;
}