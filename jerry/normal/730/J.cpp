#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N, K, a[110], b[110], x[110], sum;

int am[110][10100];

int main () {
	scanf("%d", &N);
	fo(i, 0, N) scanf("%d", &a[i]), sum += a[i];
	fo(i, 0, N) scanf("%d", &b[i]), x[i] = b[i];
	sort(x, x+N), reverse(x, x+N);

	int temp = 0;
	while (temp < sum) temp += x[K++];

	printf("%d ", K);

	fo(i, 0, 110) fo(j, 0, 10100) am[i][j] = -2e9;
	am[0][0] = 0;

	fo(n, 0, N) {
		for (int i = K; i--; ) fo(j, 0, 10100) if (j + b[n] < 10100) {
			am[i+1][j+b[n]] = max(am[i+1][j+b[n]], am[i][j] + a[n]);
		}
	}

	int ans = 0;
	fo(i, sum, 10100) {
		ans = max(ans, am[K][i]);
	}

	printf("%d\n", sum - ans);

	return 0;
}