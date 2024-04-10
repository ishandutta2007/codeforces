// Hydro submission #614447b13c975fa963d7dc1d@1631864753466
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 300010;
char S[4] = {'A', 'G', 'C', 'T'};
long long n, m, mn;
char s[N], c[6], ans[N], tmp[N], cc[6];

long long read() {
	char ch;
	long long ans = 0, f = 1;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

long long get(long long x, long long y) {
	return (x - 1) * m + y;
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> s[get(i, j)];
	mn = n * m;
	for (cc[1] = 0; cc[1] < 4; cc[1]++)
		for (cc[2] = cc[1] + 1; cc[2] < 4; cc[2]++) {
			cc[3] = cc[4] = 0;
			for (; cc[3] < 4; cc[3]++) if (cc[3] != cc[1] && cc[3] != cc[2]) break;
			for (; cc[4] < 4; cc[4]++) if (cc[4] != cc[1] && cc[4] != cc[2] && cc[4] != cc[3]) break;
			for (int i = 1; i <= 4; i++) c[i] = S[cc[i]];
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				int c1 = 0, c2 = 0;
				for (int j = 1; j <= m; j++) {
					if (j & 1 && i & 1) {
						if (s[get(i, j)] == c[1]) c1++;
						if (s[get(i, j)] == c[2]) c2++;
					}
					else if (j & 1 && !(i & 1)) {
						if (s[get(i, j)] == c[3]) c1++;
						if (s[get(i, j)] == c[4]) c2++;
					}
					else if (!(j & 1) && i & 1) {
						if (s[get(i, j)] == c[2]) c1++;
						if (s[get(i, j)] == c[1]) c2++;
					}
					else {
						if (s[get(i, j)] == c[4]) c1++;
						if (s[get(i, j)] == c[3]) c2++;
					}
				}
				if (c1 > c2) {
					for (int j = 1; j <= m; j++) {
						if (j & 1 && i & 1) 
							tmp[get(i, j)] = c[1];
						else if (j & 1 && !(i & 1)) 
							tmp[get(i, j)] = c[3];
						else if (!(j & 1) && i & 1) 
							tmp[get(i, j)] = c[2];
						else 
							tmp[get(i, j)] = c[4];
					}
					sum += m - c1;
				}
				else {
					for (int j = 1; j <= m; j++) {
						if (j & 1 && i & 1) 
							tmp[get(i, j)] = c[2];
						else if (j & 1 && !(i & 1)) 
							tmp[get(i, j)] = c[4];
						else if (!(j & 1) && i & 1) 
							tmp[get(i, j)] = c[1];
						else 
							tmp[get(i, j)] = c[3];
					}
					sum += m - c2;
				}
			}
			/*for (int i = 1; i <= 4; i++) printf("%c ", c[i]);
			printf("\n%d\n", sum);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					printf("%c", tmp[get(i, j)]);
				printf("\n");
			}*/
			if (mn > sum) {
				mn = sum;
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= m; j++)
						ans[get(i, j)] = tmp[get(i, j)];
			}
			sum = 0;
			for (int j = 1; j <= m; j++) {
				int c1 = 0, c2 = 0;
				for (int i = 1; i <= n; i++) {
					if (i & 1 && j & 1) {
						if (s[get(i, j)] == c[1]) c1++;
						if (s[get(i, j)] == c[2]) c2++;
					}
					else if (i & 1 && !(j & 1)) {
						if (s[get(i, j)] == c[3]) c1++;
						if (s[get(i, j)] == c[4]) c2++;
					}
					else if (!(i & 1) && j & 1) {
						if (s[get(i, j)] == c[2]) c1++;
						if (s[get(i, j)] == c[1]) c2++;
					}
					else {
						if (s[get(i, j)] == c[4]) c1++;
						if (s[get(i, j)] == c[3]) c2++;
					}
				}
				if (c1 > c2) {
					for (int i = 1; i <= n; i++) {
						if (i & 1 && j & 1) 
							tmp[get(i, j)] = c[1];
						else if (i & 1 && !(j & 1)) 
							tmp[get(i, j)] = c[3];
						else if (!(i & 1) && j & 1) 
							tmp[get(i, j)] = c[2];
						else 
							tmp[get(i, j)] = c[4];
					}
					sum += n - c1;
				}
				else {
					for (int i = 1; i <= n; i++) {
						if (i & 1 && j & 1) 
							tmp[get(i, j)] = c[2];
						else if (i & 1 && !(j & 1)) 
							tmp[get(i, j)] = c[4];
						else if (!(i & 1) && j & 1) 
							tmp[get(i, j)] = c[1];
						else 
							tmp[get(i, j)] = c[3];
					}
					sum += n - c2;
				}
			}
			/*printf("%d\n", sum);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					printf("%c", tmp[get(i, j)]);
				printf("\n");
			}*/ 
			if (mn > sum) {
				mn = sum;
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= m; j++)
						ans[get(i, j)] = tmp[get(i, j)];
			}
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%c", ans[get(i, j)]);
		printf("\n");
	}
	return 0;
}