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
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000;

//int mod = 1000 * 1000 * 1000 + 9;




int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	ll y1, y2, y3, x, y, r;
	cin >> y1 >> y2 >> y3 >> x >> y >> r;
	y = y3 + y3 - y - 2 * r;
	ll a = y - y1 - r;
	ll b = -x;
	ll c = -b * (y1 + r);
	if (abs((double)(b * y2 + c)) <= sqrt((double)(a * a + b * b)) * r) {
		cout << -1 << endl;
		return 0;
	}
	double res = (double)(-c - b * (y3 - r)) / a;
	printf("%0.12f\n", res);
	return 0;
}