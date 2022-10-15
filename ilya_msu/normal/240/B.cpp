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
#include<ctime>
 
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
using std::clock;
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
const int INF = 100 * 1000;
const int bound = 40001;
int d[200][2][bound];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 200; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < bound; ++k)
				d[i][j][k] = INF;
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	vector<int> h(n), s(n + 1);
	s[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		s[i + 1] = s[i] + h[i];
	}
	
	if (a < b)
		swap(a, b);
	int m = s[n] - a;
	if (m <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			d[0][1][h[0]] = 0;
			d[0][0][0] = 0;
			continue;
		}
		for (int j = 0; j < bound; ++j) {
			if (d[i - 1][0][j] != INF) {
				d[i][0][j] = min(d[i][0][j], d[i - 1][0][j]);
				d[i][1][j + h[i]] = min(d[i][1][j + h[i]], d[i - 1][0][j] + min(h[i], h[i - 1]));
			}
			if (d[i - 1][1][j] != INF) {
				d[i][0][j] = min(d[i][0][j], d[i - 1][1][j] + min(h[i], h[i - 1]));
				d[i][1][j + h[i]] = min(d[i][1][j + h[i]], d[i - 1][1][j]);
			}
		}
	}
	int res = INF;
	for (int i = m; i <= b; ++i) {
		res = min(res, d[n - 1][0][i]);
		res = min(res, d[n - 1][1][i]);
	}
	if (res < INF)
		cout << res << endl;
	else
		cout << -1 << endl;

	return 0;
}