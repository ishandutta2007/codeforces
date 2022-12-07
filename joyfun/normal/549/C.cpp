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

int n, k, x[2];

int main() {
	scanf("%d%d", &n, &k);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		x[a % 2]++;
	}
	n -= k; int f = 1;
	if (n % 2 == 0) {
		if (n / 2 >= x[0] && k % 2) {}
		else {
			if (n == 0 && x[1] % 2) {}
			else f = 0;
		}
	} else {
		if (x[1] <= n / 2) f = 0;
		if (k % 2 == 0 && x[0] <= n / 2) f = 0;

	}
	printf("%s\n", f ? "Stannis" : "Daenerys");
	return 0;
}