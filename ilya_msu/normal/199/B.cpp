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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	//freopen("input.txt", "r", stdin);
	int x1, y1, r1, R1, x2, y2, r2, R2;
	cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;
	int res = 0;
	int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if ((((r2 - r1) * (r2 - r1) >= dist) && (r2 > r1)) ||
		(((r1 - R2) * (r1 - R2) >= dist) && (r1 > R2)) ||
		((r1 + R2) * (r1 + R2) <= dist))
		++res;
	if ((((r2 - R1) * (r2 - R1) >= dist) && (r2 > R1)) ||
		(((R1 - R2) * (R1 - R2) >= dist) && (R1 > R2)) ||
		((R1 + R2) * (R1 + R2) <= dist))
		++res;
	if ((((r2 - r1) * (r2 - r1) >= dist) && (r1 > r2)) ||
		(((R1 - r2) * (R1 - r2) >= dist) && (r2 > R1)) ||
		((r2 + R1) * (r2 + R1) <= dist))
		++res;
	if ((((r1 - R2) * (r1 - R2) >= dist) && (r1 > R2)) ||
		(((R1 - R2) * (R1 - R2) >= dist) && (R2 > R1)) ||
		((R1 + R2) * (R1 + R2) <= dist))
		++res;
	cout << res << endl;
 	return 0;
}