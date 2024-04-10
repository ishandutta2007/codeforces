#include <algorithm>
#include <cstdio>
using namespace std;

#define pb push_back

typedef long long ll;

const int D = 5001;
const int N = 10010;
 
int n, bit[N];
void clr() { fill(bit, bit + N, 0); }
void ins(int u, int v) {
	for(; u < N; u += u & (-u)) bit[u] += v;
}
int qry(int u) {
	int ans = 0;
	for(; u >= 1; u &= u - 1) ans += bit[u];
	return ans;
}

struct Node { int a, l, r; };
vector<Node> x, y;

bool cmp1(const Node &a, const Node &b) { return a.a < b.a; }
bool cmp2(const Node &a, const Node &b) { return a.r > b.r; }

int main() {
	scanf("%d", &n);
	int x1, y1, x2, y2;
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 += D; y1 += D; x2 += D; y2 += D;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		if(x1 == x2) x.pb((Node) {x1, y1, y2});
		if(y1 == y2) y.pb((Node) {y1, x1, x2});
	}
	sort(x.begin(), x.end(), cmp2);
	sort(y.begin(), y.end(), cmp1);
	ll ans = 0;
	for(int i = 0; i < y.size(); i ++) {
		clr(); int p = 0;
		for(int j = (int) y.size() - 1; j > i; j --) {
			while(p != x.size() && x[p].r >= y[j].a) {
				if(y[i].l <= x[p].a && x[p].a <= y[i].r && x[p].l <= y[i].a) {
					ins(x[p].a, 1);
				}
				p ++;
			}
			int cnt = qry(y[j].r) - qry(y[j].l - 1);
			if(cnt) ans += 1ll * cnt * (cnt - 1) / 2;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}