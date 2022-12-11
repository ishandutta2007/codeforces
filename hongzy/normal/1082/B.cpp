#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, m, c[N], t[N];
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i ++) {
		if(s[i] == s[i - 1]) c[m] ++;
		else {
			t[++ m] = s[i] == 'G';
			c[m] = 1;
		}
	}
	bool tag = 0;
	for(int i = 1; i <= m; i ++)
		if(!t[i] && c[i] == 1) tag = 1, i = m;
	int g = 0, a = 0;
	for(int i = 1; i <= m; i ++)
		if(t[i]) ++ g, a = max(a, c[i]);
	if(g > 1) a ++;
	for(int i = 1; i <= m; i ++) if(!t[i] && c[i] == 1) {
		if(i == 1 && i != m) a = max(a, c[i + 1] + (int) (g > 1));
		if(i != 1 && i == m) a = max(a, c[i - 1] + (int) (g > 1));
		if(i != 1 && i != m && c[i] == 1)
			a = max(a, c[i - 1] + c[i + 1] + (int) (g > 2));
	}
	printf("%d\n", a);
	return 0;
}