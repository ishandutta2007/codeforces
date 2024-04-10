#include<bits/stdc++.h>
using namespace std;
string s[40];
int mh[40][40][40],num[40][40][40][40],h[40];
int main() {
	int n, m, q,i,j,k,l;
	scanf("%d%d%d", &n, &m, &q);
	for (i = 0; i < n; i++)cin >> s[i];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (s[i][j] == '0')h[j]++;
			else h[j] = 0;
		}
		for (j = 0; j < m; j++) {
			int sm = h[j];
			for (k = j; k < m; k++) {
				sm = min(sm, h[k]);
				mh[i][j][k] = sm;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (l = i; l >= 0; l--) {
				num[i][j][j][l] = min(mh[i][j][j], i-l + 1);
				for (k = j + 1; k < m; k++)num[i][j][k][l] = num[i][j][k - 1][l] + min(mh[i][j][k],i-l + 1);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (l = i; l >= 0; l--) {
			for (k = m - 1; k >= 0; k--) {
				for (j = k - 1; j >= 0; j--)num[i][j][k][l] += num[i][j + 1][k][l];
			}
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (k = j; k < m; k++) {
				for (l = i; l >= 0; l--) {
					num[i][j][k][l] += num[i - 1][j][k][l];
				}
			}
		}
	}
	int a, b, c, d;
	while (q--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", num[c - 1][b - 1][d - 1][a - 1]);
	}
}