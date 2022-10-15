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

int fu(int time, int m, int fl) {
	int t = time % (2 * m - 2);
	int fl0;
	if (t <= m - 1)
		fl0 = t + 1;
	else
		fl0 = 2 * m - 1 - t;
	if (t <= m - 1) {
		if (fl >= fl0)
			return time + fl - fl0;
		return time + m - fl0 + m - fl;
	}
	if (fl0 >= fl)
		return fl0 - fl + time;
	return fl0 + fl - 2 + time;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int s, f, t;
		cin >> s >> f >> t;
		int t1 = fu(t, m, s);
		int t2 = fu(t1, m, f);
		if (s == f)
			cout << t << endl;
		else
			cout << t2 << endl;
	}
	return 0;
}