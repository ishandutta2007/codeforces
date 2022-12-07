#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int mod = 1000000007;
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	printf("%d\n", (3 * n * 2 - 1) * k);
	for (int i = 1; i <= n; i++) {
		printf("%d %d %d %d\n", (i * 6 - 5) * k, (i * 6 - 4) * k, (i * 6 - 3) * k, (i * 6 - 1) * k);
	}
	return 0;
}