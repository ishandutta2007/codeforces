#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint() {
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') {
		res = res * 10 + c - '0';
	}
	return res;
}

const int MaxN = 100005;
const int MaxM = 100005;
const int MaxNK = 100005;

int n, m, nK;
int fx[MaxNK], fy[MaxNK];
s64 res[MaxNK];

vector<int> s[MaxN + MaxM];
vector<int> d[MaxN + MaxM];
bool bs[MaxN + MaxM];
bool bd[MaxN + MaxM];

int main() {
	cin >> n >> m >> nK;
	for (int i = 1; i <= nK; ++i) {
		fx[i] = getint(), fy[i] = getint();
		s[fx[i] + fy[i] + 0].push_back(i);
		d[fx[i] - fy[i] + m].push_back(i);
		res[i] = -1;
	}

	int dx = 0, dy = 0, dir = 0;
	s64 sum = 0;
	while (true) {
		int k;
		if (dir == 0) {
			int l = dx - dy + m;
			for (int i : d[l]) {
				if (!~res[i]) {
					res[i] = sum + fx[i] - dx;
				}
			}
			if (bd[l]) {
				break;
			}
			bd[l] = true;

			if (n - dx < m - dy) {
				dy += (k = n - dx), dx = n, dir = 1;
			} else {
				dx += (k = m - dy), dy = m, dir = 3;
			}
		} else if (dir == 1) {
			int l = dx + dy;
			for (int i : s[l]) {
				if (!~res[i]) {
					res[i] = sum + fy[i] - dy;
				}
			}
			if (bs[l]) {
				break;
			}
			bs[l] = true;

			if (dx < m - dy) {
				dy += (k = dx), dx = 0, dir = 0;
			} else {
				dx -= (k = m - dy), dy = m, dir = 2;
			}
		} else if (dir == 2) {
			int l = dx - dy + m;
			for (int i : d[l]) {
				if (!~res[i]) {
					res[i] = sum + dy - fy[i];
				}
			}
			if (bd[l]) {
				break;
			}
			bd[l] = true;

			if (dx < dy) {
				dy -= (k = dx), dx = 0, dir = 3;
			} else {
				dx -= (k = dy), dy = 0, dir = 1;
			}
		} else if (dir == 3) {
			int l = dx + dy;
			for (int i : s[l]) {
				if (!~res[i]) {
					res[i] = sum + fx[i] - dx;
				}
			}
			if (bs[l]) {
				break;
			}
			bs[l] = true;

			if (n - dx < dy) {
				dy -= (k = n - dx), dx = n, dir = 2;
			} else {
				dx += (k = dy), dy = 0, dir = 0;
			}
		}

		sum += k;
		if ((dx == 0 || dx == n) && (dy == 0 || dy == m)) {
			break;
		}
	//	cout << dx << ' ' << dy << ' ' << dir << endl;
	//	system("pause>nul");
	}

	for (int i = 1; i <= nK; ++i) {
		printf("%I64d\n", res[i]);
	}

	return 0;
}