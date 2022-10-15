#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const int M = 300;

ll d[M][M];
int s;
ll get(int x, int y) {
	if (d[x][y] != -1)
		return d[x][y];
	d[x][y] = d[x - 1][y] + d[x][y - 1] - d[x - 1][y - 1];
	int w = 2 * x + 1;
	int h = 2 * y + 1;
	if (w * h < s)
		return d[x][y];
	if (w * h == s) {
		d[x][y] += 2 * (x + 1) * (y + 1) - 1;
		return d[x][y];
	}
	int ss = w * h - s;
	if (ss % 4 != 0)
		return d[x][y];
	ss /= 4;
	for (int dx = 1; dx <= x; ++dx) {
		int dy = ss / dx;
		if ((dy <= y) && (dy * dx == ss))
			d[x][y] += 2;
	}
	return d[x][y];		
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m >> s;
	ll res = 0;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			d[i][j] = -1;
	if (s == 1) {
		cout << m * n << endl;
		return 0;
	}
	if (s % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < M; ++i) {
		d[i][0] = d[0][i] = int(i - s / 2 + 1 > 0) * s;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = min(i, n - i - 1);
			int y = min(j, m - j - 1);
			res += get(x, y);
		}
	}
	cout << res << endl;	
	return 0;
}