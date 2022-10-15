#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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



int main() {
	int m, k;
	cin >> m >> k;
	vector<int> d(m), s(m);
	for (int i = 0; i < m; ++i)
		cin >> d[i];
	for (int i = 0; i < m; ++i)
		cin >> s[i];
	int x = s[0];
	int t = 0;
	int n = x;
	for (int i = 0; i < m; ++i) {
		while(n < d[i]) {
			n += x;
			t += k;
		}
		n -= d[i];
		t += d[i];
		if (i + 1 < m) {
			x = max(x, s[i + 1]);
			n += s[i + 1];
		}
	}
	cout << t << endl;
	return 0;
}