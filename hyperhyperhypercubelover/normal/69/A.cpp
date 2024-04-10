#include <cstdio>

int main() {
	int x, y, z;
	int tx, ty, tz;
	int n;
	scanf("%d", &n);
	x = y = z = 0;
	while (n--) {
		scanf("%d%d%d", &tx, &ty, &tz);
		x += tx;
		y += ty;
		z += tz;
	}
	puts(x || y || z ? "NO" : "YES");
}