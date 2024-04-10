#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N, A, B, dp[3300][3300], f[3300][3300];
set<int> as, bs;

struct thing {
	int x, y, i;
	bool operator < (const thing &o) const {
		return x > o.x;
	}
} a[3300];

int main () {
	scanf("%d %d %d", &N, &A, &B);
	fo(i, 0, N) scanf("%d", &a[i].x);
	fo(i, 0, N) scanf("%d", &a[i].y), a[i].i = i;
	sort(a, a+N);

	fo(i, 0, 3300) fo(j, 0, 3300) dp[i][j] = -2e9;

	int sum = 0;
	fo(i, 0, A) sum += a[i].x;

	dp[0][0] = sum;

	fo(i, 0, B+1) fo(j, 0, N) {
		if (dp[i][j] > dp[i][j+1]) {
			dp[i][j+1] = dp[i][j];
			f[i][j+1] = 1; //i didn't choose i-1
		}
		int c = a[j].y;
		if (j <= A-1+i) {
			c -= a[j].x;
			c += a[A+i].x;
		}
		if (dp[i][j] + c > dp[i+1][j+1]) {
			dp[i+1][j+1] = dp[i][j] + c;
			f[i+1][j+1] = 2; //i chose i-1
		}
	}

	printf("%d\n", dp[B][N]);

	for (int i = B, j = N; j > 0;) {
		assert(f[i][j]);
		if (f[i][j] == 1) {
			j--;
		} else {
			i--, j--;
			bs.insert(j);
		}
	}
	assert((int) bs.size() == B);

	fo(i, 0, N) if ((int) as.size() < A && !bs.count(i)) as.insert(i);

	for (int i : as) printf("%d ", 1+a[i].i); puts("");
	for (int i : bs) printf("%d ", 1+a[i].i); puts("");

	return 0;
}