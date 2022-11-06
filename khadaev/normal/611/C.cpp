#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 500;
char c[N][N];
int hor[N][N], ver[N][N];

int get_hor(int i, int j) {
	if (i < 0 || j < 0) return 0;
	return hor[i][j];
}

int get_ver(int i, int j) {
	if (i < 0 || j < 0) return 0;
	return ver[i][j];
}

int get_ver_ans(int r1, int c1, int r2, int c2) {
	--r2;
	--r1;
	--c1;
	return get_ver(r2, c2) - get_ver(r1, c2) - get_ver(r2, c1) +
	get_ver(r1, c1);
}

int get_hor_ans(int r1, int c1, int r2, int c2) {
	--c2;
	--c1;
	--r1;
	return get_hor(r2, c2) - get_hor(r1, c2) - get_hor(r2, c1) +
	get_hor(r1, c1);
}

int ans(int r1, int c1, int r2, int c2) {
	return get_ver_ans(r1, c1, r2, c2) + get_hor_ans(r1, c1, r2, c2);
}


int main() {
	int h, w;
	scanf("%d%d\n", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%c", &c[i][j]);
		}
		scanf("\n");
	}
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w - 1; ++j)
			hor[i][j] = (c[i][j] == '.' && c[i][j + 1] == '.');
	for (int i = 0; i < h - 1; ++i)
		for (int j = 0; j < w; ++j)
			ver[i][j] = (c[i][j] == '.' && c[i + 1][j] == '.');
	for (int i = 0; i < h; ++i)
		for (int j = 1; j < w - 1; ++j)
			hor[i][j] += hor[i][j - 1];
	for (int i = 1; i < h; ++i)
		for (int j = 0; j < w - 1; ++j)
			hor[i][j] += hor[i - 1][j];
	for (int i = 0; i < h - 1; ++i)
		for (int j = 1; j < w; ++j)
			ver[i][j] += ver[i][j - 1];
	for (int i = 1; i < h - 1; ++i)
		for (int j = 0; j < w; ++j)
			ver[i][j] += ver[i - 1][j];
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		--c1, --c2, --r1, --r2;
		cout << ans(r1, c1, r2, c2) << '\n';		
	}
	/*for (int i = 0; i < h - 1; ++i) {
		for (int j = 0; j < w; ++j)
			cout << ver[i][j] << ' ';
		cout << '\n';
	}*/
}