/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int hp[2], dt[2], l[2], r[2];
ld p[2];

const int maxn = 201;

ld dp[30 * 2 + 1][maxn][maxn];
ld sum[2][30 * 2 + 1][maxn][maxn];

ld getsum(int it, int pos, int l, int r, int x) {
	if (it == 0) {
		return (r <= 0 ? (r - l + 1) * sum[it][pos][0][x] : (l <= 0 ? sum[it][pos][r][x] + (-l) * sum[it][pos][0][x] : sum[it][pos][r][x] - sum[it][pos][l - 1][x]));
	} else {
	    return (r <= 0 ? (r - l + 1) * sum[it][pos][x][0] : (l <= 0 ? sum[it][pos][x][r] + (-l) * sum[it][pos][x][0] : sum[it][pos][x][r] - sum[it][pos][x][l - 1]));
	}
}

void change(int a, int b, int pos, ld x) {
	dp[pos][a][b] = x;
	sum[0][pos][a][b] = x + sum[0][pos][a - 1][b];
	sum[1][pos][a][b] = x + sum[1][pos][a][b - 1];
}

vector <pii> v;

ld getsums(int a, int b, int pos) {
	int z = (int)v.size();

	ld sums = 0;

	int i = pos;
	
	ld q = 1;

	while (true) {
		int ps = i + 1;
		if (ps == z) {
			ps = 0;
		}

		if (v[i].second == 0) {
			ld g = q * getsum(1, ps, b - r[0], b - l[0], a) * (1 - p[0]);

			g /= (r[0] - l[0] + 1);
			sums += g;
		} else {
			ld g = q * getsum(0, ps, a - r[1], a - l[1], b) * (1 - p[1]);
			g /= (r[1] - l[1] + 1);
			sums += g;
		}

		if (p[v[i].second] == 0) {
			break;
		}
		
		q *= p[v[i].second];

		i = ps;

		if (i == pos) {
			return sums / (1 - q);
		}
	}

	return sums;
}

int main() {
	for (int i = 0; i < 2; i++) {
		cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> p[i];
		p[i] /= 100;
	}

	for (int i = 0; i < dt[1]; i++) {
		v.push_back(mp(i * dt[0], 0));
	}

	for (int i = 0; i < dt[0]; i++) {
		v.push_back(mp(i * dt[1], 1));
	}

	int z = (int)v.size();

	sort(v.begin(), v.end());

	if (p[0] == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (p[1] == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < z; i++) {
		for (int a = 0; a <= hp[0]; a++) {
			dp[i][a][0] = 1.0;
			sum[0][i][a][0] = dp[i][a][0] + (a == 0 ? 0 : sum[0][i][a - 1][0]);
			sum[1][i][a][0] = dp[i][a][0];
		}
	}

	for (int a = 1; a <= hp[0]; a++) {
		for (int b = 1; b <= hp[1]; b++) {
			for (int ps = 0; ps < (int)v.size(); ps++) {
				ld sums = getsums(a, b, ps);
				change(a, b, ps, sums);
			}
		}
	}

	printf("%.10lf\n", dp[0][hp[0]][hp[1]]);

	return 0;
}