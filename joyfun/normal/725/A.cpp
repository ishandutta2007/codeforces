#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
int n;
char str[N];
int vis[N];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		if (str[i] == '>') break;
		vis[i] = 1;
	}
	for (int i = n; i >= 1; i--) {
		if (str[i] == '<') break;
		vis[i] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += vis[i];
	printf("%d\n", ans);
	return 0;
}