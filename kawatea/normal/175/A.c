#include <stdio.h>
#include <string.h>

int main()
{
	int n, m = -1, i, j, k;
	char s[31];

	scanf("%s", s);

	n = strlen(s);

	for (i = 0; i < n - 2; i++) {
		for (j = i + 1; j < n - 1; j++) {
			int x = 0, y = 0, z = 0;

			for (k = 0; k < n; k++) {
				if (k <= i) {
					x *= 10;
					x += s[k] - '0';

					if (x > 1000000) break;
				} else if (k <= j) {
					y *= 10;
					y += s[k] - '0';

					if (y > 1000000) break;
				} else {
					z *= 10;
					z += s[k] - '0';

					if (z > 1000000) break;
				}
			}

			if (k < n) continue;

			if (i > 0 && s[0] == '0') continue;

			if (j - i > 1 && s[i + 1] == '0') continue;

			if (j < n - 2 && s[j + 1] == '0') continue;

			if (x + y + z > m) m = x + y + z;
		}
	}

	printf("%d\n", m);

	return 0;
}