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
const double eps = 1e-12;
const int INF = 1000 * 1000 + 10;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> b(m, 0), w(m, 0);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			if (s[j] == '#')
				++b[j];
			else
				++w[j];
	}
	vector<vector<int> > db(m, vector<int>(y, INF)), dw(m, vector<int>(y, INF));
	db[0][0] = b[0];
	dw[0][0] = w[0];
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < y; ++j) {
			if (db[i - 1][j] != INF) {
				if (j + 1 >= x) {
					dw[i][0] = min(db[i - 1][j] + w[i], dw[i][0]);
				}
				if (j + 1 < y)
					db[i][j + 1] = min(db[i - 1][j] + b[i], db[i][j + 1]);
			}
			if (dw[i - 1][j] != INF) {
				if (j + 1 >= x) {
					db[i][0] = min(dw[i - 1][j] + b[i], db[i][0]);
				}
				if (j + 1 < y)
					dw[i][j + 1] = min(dw[i - 1][j] + w[i], dw[i][j + 1]);
			}
		}
	}
	int ans = INF;
	for (int i = x - 1; i < y; ++i)
		ans = min(ans, min(dw[m - 1][i], db[m - 1][i]));
	cout << ans << endl;
	return 0;
}