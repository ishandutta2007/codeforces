#include <cstdio>
#include <cstring>

char s[111111];
char d[111111];
int dn;
int x[111111];
int y[111111];

int main() {
	int mx, mxi, mxj;
	int i, j, k, n;
	scanf("%s", s);
	n = strlen(s);
	mx = mxi = mxj = 0;
	x[0] = 0;
	y[0] = 0;
	for (i = j = k = 0; i < n; i++) {
		if (s[i] == ')') {
			if (!dn || d[dn] != '(') {
				j = i + 1;
				k = 0;
				dn = 0;
				x[0] = i + 1;
				y[0] = 0;
				continue;
			}
			dn--;
			if (k - y[dn] > mx) {
				mx = k - y[dn];
				mxi = x[dn];
				mxj = i + 1;
			}
		}
		else if (s[i] == ']') {
			if (!dn || d[dn] != '[') {
				j = i + 1;
				k = 0;
				dn = 0;
				x[0] = i + 1;
				continue;
			}
			dn--;
			k++;
			if (k - y[dn] > mx) {
				mx = k - y[dn];
				mxi = x[dn];
				mxj = i + 1;
			}
		}
		else {
			dn++;
			d[dn] = s[i];
			x[dn] = i + 1;
			y[dn] = k;
		}
	}
	printf("%d\n", mx);
	s[mxj] = 0;
	puts(s + mxi);
	return 0;
}