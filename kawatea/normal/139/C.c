#include <stdio.h>
#include <string.h>

int main()
{
    int n, p, ans = 0, i, j, k, l;
    char s[4][10001];
    char c[5] = "aiueo";

    scanf("%d %d", &n, &p);

    for (i = 0; i < n; i++) {
	int a[4] = {0};
	int b[4];

	for (j = 0; j < 4; j++) scanf("%s", s[j]);

	for (j = 0; j < 4; j++) {
	    a[j] = strlen(s[j]);

	    for (k = 0; k < a[j] / 2; k++) {
		char tmp = s[j][k];

		s[j][k] = s[j][a[j] - k - 1];
		s[j][a[j] - k - 1] = tmp;
	    }
	}

	if (ans == -1) continue;

	if (ans == 1) {
	    for (j = 0; j < 4; j++) b[j] = j;
	} else if (ans == 2) {
	    b[0] = 0;
	    b[1] = 2;
	    b[2] = 1;
	    b[3] = 3;
	} else if (ans == 3) {
	    b[0] = 0;
	    b[1] = 3;
	    b[2] = 1;
	    b[3] = 2;
	}

	if (ans > 0) {
	    int q = 0, f = 0;

	    for (j = 0; j < a[b[0]] && j < a[b[1]]; j++) {
		if (s[b[0]][j] != s[b[1]][j]) break;

		for (k = 0; k < 5; k++) {
		    if (s[b[0]][j] == c[k]) break;
		}

		if (k < 5) {
		    if (++q == p) {
			f++;

			break;
		    }
		}
	    }

	    q = 0;

	    for (j = 0; j < a[b[2]] && j < a[b[3]]; j++) {
		if (s[b[2]][j] != s[b[3]][j]) break;

		for (k = 0; k < 5; k++) {
		    if (s[b[2]][j] == c[k]) break;
		}

		if (k < 5) {
		    if (++q == p) {
			f++;

			break;
		    }
		}
	    }

	    if (f != 2) ans = -1;
	} else {
	    int q = 0, f = 0, m = 0, x, y;

	    for (j = 1; j <= 3; j++) {
		q = 0;
		f = 0;

		for (k = 0; k < a[0] && k < a[j]; k++) {
		    if (s[0][k] != s[j][k]) break;

		    for (l = 0; l < 5; l++) {
			if (s[0][k] == c[l]) break;
		    }

		    if (l < 5) {
			if (++q == p) {
			    f = 1;

			    break;
			}
		    }
		}

		if (f == 1) {
		    m = j;

		    break;
		}
	    }

	    if (m == 0) {
		ans = -1;

		continue;
	    }

	    if (m == 1) {
		x = 2;
		y = 3;
	    } else if (m == 2) {
		x = 1;
		y = 3;
	    } else {
		x = 1;
		y = 2;
	    }

	    q = 0;
	    f = 0;

	    for (j = 0; j < a[x] && j < a[y]; j++) {
		if (s[x][j] != s[y][j]) break;

		for (k = 0; k < 5; k++) {
		    if (s[x][j] == c[k]) break;
		}

		if (k < 5) {
		    if (++q == p) {
			f = 1;

			break;
		    }
		}
	    }

	    if (f == 0) {
		ans = -1;

		continue;
	    }

	    ans = m;

	    q = 0;
	    f = 0;

	    for (j = 0; j < a[0] && j < a[x]; j++) {
		if (s[0][j] != s[x][j]) break;

		for (k = 0; k < 5; k++) {
		    if (s[0][j] == c[k]) break;
		}

		if (k < 5) {
		    if (++q == p) {
			f = 1;

			break;
		    }
		}
	    }

	    if (f == 1) ans = 0;
	}
    }

    if (ans == -1) {
	puts("NO");
    } else if (ans == 1) {
	puts("aabb");
    } else if (ans == 2) {
	puts("abab");
    } else if (ans == 3) {
	puts("abba");
    } else {
	puts("aaaa");
    }

    return 0;
}