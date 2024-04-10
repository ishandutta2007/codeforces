#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n;
	scanf("%d", &n);
	vector <vector <int> > v(n, vector <int> (n));
	int x = 0, y = (n - 1) / 2;
	rep(i, n * n) {
		v[x][y] = i + 1;
		-- x; ++ y;
		if (x < 0 && y >= n) { x += 2; -- y; }
		else if (x < 0) x = n - 1;
		else if (y >= n) y = 0;
		else if (v[x][y]) { x += 2; -- y; }
	}
{
	rep(i, n) {
		int s = 0;
		rep(j, n) s += v[i][j];
		assert(s & 1);
		s = 0;
		rep(j, n) s += v[j][i];
		assert(s & 1);
	}
	int s = 0;
	rep(i, n) s += v[i][i];
	assert(s & 1);
	s = 0;
	rep(i, n) s += v[i][n - 1 - i];
	assert(s & 1);
}
	rep(i, n) {
		rep(j, n) {
			if (j) printf(" ");
			printf("%d", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}