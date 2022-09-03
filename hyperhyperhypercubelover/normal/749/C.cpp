#include <cstdio>

char a[200002];
int b[200002];

int main() {
	int i, n, m, t = 0;
	scanf("%d%s", &n, a);
	m = 3;
	while (m == 3) {
		m = 0;
		for (i = 0; i < n; i++) if (!b[i]) {
			if (a[i] == 'D') {
				m |= 1;
				if (t > 0) {
					b[i] = 1;
					t--;
				}
				else t--;
			}
			else {
				m |= 2;
				if (t < 0) {
					b[i] = 1;
					t++;
				}
				else t++;
			}
		}
	}
	puts(t > 0 ? "R" : "D");
}