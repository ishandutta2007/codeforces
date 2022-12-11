#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 5e5 + 20;
const int P = 701;

int q, op[N], qwq[N], a[N], b[N], n;
ll sum[P][P];
void add(int x, int z) {
	for(int i = 1; i < P; i ++) {
		int y = (x % i + i) % i;
		sum[i][y] += z;
	}
}
int main() {
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d%d", op + i, a + i, b + i);
		if(op[i] == 1) add(a[i], b[i]), qwq[a[i]] += b[i];
		if(op[i] == 2) {
			if(a[i] < P) printf("%I64d\n", sum[a[i]][b[i]]);
			else {
				ll ans = 0;
				for(int j = b[i]; j <= 500000; j += a[i]) ans += qwq[j];
				printf("%I64d\n", ans);
			}
		}
	}
	return 0;
}