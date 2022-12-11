#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n, b[N], a[N], cnt[N];
int main() {
	// freopen("input", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i), b[i] = a[i];
	for(int i = 1 << 30; i >= 1; i >>= 1) {
		int cnt = 0;
		for(int j = 1; j <= n; j ++) cnt += b[j] >= i;
		if(cnt == 0) continue ;
		if(cnt == 1) break ;
		for(int j = 1; j <= n; j ++) if(b[j] >= i) b[j] -= i;
	}
	for(int i = 1; i <= n; i ++) {
		if(b[i] > b[1]) swap(b[1], b[i]), swap(a[1], a[i]);
	}
	for(int i = 1; i <= n; i ++) printf("%d ", a[i]);
	return 0;
	int x = a[1];
	for(int i = 2; i <= n; i ++) x = (x | a[i]) - a[i];
	printf("%d!\n", x);
	return 0;
}