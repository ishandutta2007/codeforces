#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int n, p;
char str[N];

bool solve(int u) {
	if (u < 0) return false;
	str[u]++;
	if (str[u] - 'a' == p) {
		if (solve(u - 1)) {
			str[u] = 'a' - 1;
			return solve(u);
		}
	} else {
		if (u - 1 >= 0 && str[u] == str[u - 1]) return solve(u);
		if (u - 2 >= 0 && str[u] == str[u - 2]) return solve(u);
		return true;
	}
}

int main() {
	scanf("%d%d", &n, &p);
	scanf("%s", str);
	if (solve(n - 1)) printf("%s\n", str);
	else printf("NO\n");
	return 0;
}