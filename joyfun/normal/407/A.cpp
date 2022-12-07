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

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	for (int x = 1; x < a; x++) {
		int y = sqrt(a * a - x * x + 0.5);
		if (y * y != a * a - x * x) continue;
		for (int xx = 1; xx < b; xx++) {
			int yy = -sqrt(b * b - xx * xx + 0.5);
			if (yy * yy != b * b - xx * xx) continue;
			if (x * xx + y * yy) continue;
			if (x == xx || y == yy) continue;
			printf("YES\n");
			printf("0 0\n%d %d\n%d %d\n", x, y, xx, yy);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}