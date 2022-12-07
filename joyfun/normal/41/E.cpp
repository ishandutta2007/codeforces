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

int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", n / 2 * (n - n / 2));
	for (int i = 1; i <= n / 2; i++) {
		for (int j = n / 2 + 1; j <= n; j++)
			printf("%d %d\n", i, j);
	}
	return 0;
}