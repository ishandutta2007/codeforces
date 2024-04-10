#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;


const int N = 5005;
const int INF = 0x3f3f3f3f;

int n;

struct Node {
	int a, b;
	void read() {scanf("%d%d", &a, &b);}
	bool operator < (const Node& c) const {
		if (a == c.a) return b < c.b;
		return a < c.a;
	}
} nd[N];

int dp[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) nd[i].read();
	sort(nd + 1, nd + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (nd[i].b >= dp[i - 1]) dp[i] = nd[i].b;
		else dp[i] = nd[i].a;
	}
	printf("%d\n", dp[n]);
	return 0;
}