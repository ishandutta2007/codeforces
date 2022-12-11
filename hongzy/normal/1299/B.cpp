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
typedef double db;
const int N = 1e5 + 10;
struct point {
	ll x, y;
	void in() { int a, b; scanf("%d%d", &a, &b); x = a; y = b; }
	point operator - (point b) { return {x - b.x, y - b.y}; }
	ll to(point b) {
		return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
	}
	ll det(point b) { return x * b.y - y * b.x; }
	bool t(point b) { return to({0, 0}) == b.to({0, 0}); }
} a[N];
int n;
int main() {
	// freopen("input", "r", stdin);
	scanf("%d", &n);
	if(n & 1) return puts("NO"), 0;
	for(int i = 0; i < n; i ++) a[i].in();
	bool tag = 1;
	for(int i = 0; i < n; i ++) {
		int k = (i + (n >> 1)) % n;
		if((a[(k + 1) % n] - a[k]).det(a[(i + 1) % n] - a[i])) {
			tag = 0; break ;
		}
		if(!(a[(k + 1) % n] - a[k]).t(a[(i + 1) % n] - a[i])) {
			tag = 0; break ;
		}
	}
	puts(tag ? "YES" : "NO");
	return 0;
}