#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 610;

int n, l[N], r[N], st[N], sl[N], sr[N];
char c[N * 2], tg;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d%d", l + i, r + i);
	int top = 0, cnt = 0;
	for(int i = 1; i <= 2 * n; i ++) {
		if(!top || !(sl[top] <= i && i <= sr[top])) {
			if(++ cnt > n) { tg = 1; break ; }
			top ++; sl[top] = i + l[cnt]; sr[top] = i + r[cnt]; c[i] = '(';
		} else {
			top --; c[i] = ')';
		}
	}
	puts(tg ? "IMPOSSIBLE" : c + 1);
	return 0;
}