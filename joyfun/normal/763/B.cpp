#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n;
int c[2][2] = {1, 2, 3, 4};

int main() {
	scanf("%d", &n);
	printf("YES\n");
	while (n--) {
		int x, y;
		scanf("%d%d%*d%*d", &x, &y);
		printf("%d\n", c[abs(x) % 2][abs(y) % 2]);
	}
	return 0;
}