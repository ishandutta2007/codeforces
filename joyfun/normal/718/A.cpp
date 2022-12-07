#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
int n, t;
char str[N];
int a[N], b[N];
int vis[N];

int main() {
	scanf("%d%d", &n, &t);
	scanf("%s", str + 1);
	int an = 0; int v;
	for (int i = 1; i <= n; i++) {
		if (str[i] == '.') v = an + 1;
		else a[++an] = str[i] - '0';
	}
	for (int i = v; i <= an; i++) {
		if (a[i] >= 5) {
			for (int j = i; j >= v; j--) {
				if (vis[j] || a[j] < 5) break;
				vis[j] = 1;
				a[j] = 0;
				a[j - 1]++;
				int s = j - 1;
				while (a[s] == 10) {
					a[s] = 0;
					a[s - 1]++;
					s--;
				}
				t--;
				if (t == 0) break;
			}
			for (int j = i; j <= an; j++) a[j] = 0;
			break;
		}
		if (t== 0) break;
	}
	if (a[0]) printf("%d", a[0]);
	for (int i = 1; i < v; i++) printf("%d", a[i]);
	while (a[an] == 0) an--;
	if (an >= v) {
		printf(".");
		for (int i = v; i <= an; i++) printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}