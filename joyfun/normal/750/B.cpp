#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;
char str[15];

int main() {
	scanf("%d", &n);
	int s = 0;
	int f = 1;
	while (n--) {
		scanf("%d%s", &t, str);
		if (str[0] == 'S') s += t;
		if (str[0] == 'N') s -= t;
		if (str[0] == 'W' || str[0] == 'E') {
			if (s == 0 || s == 20000) {
				f = 0;
			}
		}
		if (s < 0 || s > 20000) {
			f = 0;
		}
	}
	if (s != 0) f = 0;
	printf("%s\n", f ? "YES" : "NO");
	return 0;
}