#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	if (n < 4 || (n == 4 && k == 2) || k > 3 || k < 2) printf("-1\n");
	else {
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i++) printf("%d %d\n", k == 2 || i < 3 ? i : 3, i + 1);
	}
	return 0;
}