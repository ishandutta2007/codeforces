#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

int n, a, b;
int ctoi[300];
char c1[10], c2[10];
int main() {
	scanf("%s%s%d", c1, c2, &n); n &= 3;
	ctoi['<'] = 0; ctoi['^'] = 1; ctoi['>'] = 2; ctoi['v'] = 3;
	a = ctoi[*c1]; b = ctoi[*c2];
	a = ((b - a + 4) & 3);
	b = ((4 - a) & 3);
	if (a == n && b != n) {
		printf("cw"); return 0;
	}
	if (a != n && b == n) {
		printf("ccw"); return 0;
	}
	printf("undefined");
	return 0;
}