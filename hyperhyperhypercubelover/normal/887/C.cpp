#include <cstdio>

int a[24];
int ta[24];
int e[24] = { 1, 2, 3, 4, 13, 14, 15, 16, 9, 10, 11, 12, 21, 22, 23, 24, 5, 6, 7, 8, 17, 18, 19, 20 };
int b[24] = { 24, 23, 22, 21, 1, 2, 3, 4, 5, 6, 7, 8, 13, 14, 15, 16, 17, 18, 19, 20, 12, 11, 10, 9 };
int c[24] = { 18, 20, 17, 19, 5, 6, 7, 8, 14, 16, 13, 15, 2, 4, 1, 3, 10, 12, 9, 11, 21, 22, 23, 24 };
int d[24] = { 1, 2, 3, 4, 13, 14, 7, 8, 9, 10, 11, 12, 21, 22, 15, 16, 5, 6, 19, 20, 17, 18, 23, 24 };

void rot() {
	int i, j;
	for (i = 0; i < 24; i++) ta[i] = a[d[i] - 1];
}

void rot2() {
	int i, j;
	for (i = 0; i < 24; i++) ta[d[i] - 1] = a[i];
}

int chk() {
	int i, j;
	for (i = 0; i < 6; i++) for (j = 0; j < 4; j++) if (ta[i * 4 + j] != ta[i * 4]) return 0;
	return 1;
}

int main() {
	int i, j, k, l;
	for (i = 0; i < 24; i++) scanf("%d", &a[i]);
	for (l = 0; l < 7; l++) {
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				rot();
				if (chk()) {
					puts("YES");
					return 0;
				}
				rot2();
				if (chk()) {
					puts("YES");
					return 0;
				}
				for (k = 0; k < 24; k++) ta[k] = a[b[k] - 1];
				for (k = 0; k < 24; k++) a[k] = ta[k];
			}
			for (k = 0; k < 24; k++) ta[k] = a[c[k] - 1];
			for (k = 0; k < 24; k++) a[k] = ta[k];
		}
		for (k = 0; k < 24; k++) ta[k] = a[e[k] - 1];
		for (k = 0; k < 24; k++) a[k] = ta[k];
	}
	puts("NO");
	return 0;
}