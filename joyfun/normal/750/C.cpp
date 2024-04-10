#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;

int main() {
	scanf("%d", &n);
	int c, tp;
	int s = 0;
	int Max = INF, Min = -INF;
	while (n--) {
		scanf("%d%d", &c, &tp);
		if (tp == 1) {
			Min = max(1900 - s, Min);
		} else {
			Max = min(1899 - s, Max);
		}
		s += c;
	}
	if (Min > Max) printf("Impossible\n");
	else if (Max == INF) printf("Infinity\n");
	else printf("%d\n", Max + s);
	return 0;
}