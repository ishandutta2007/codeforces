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
//const int INF = 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int pow(int n) {
	ll res = 1;
	ll m = 2;
	while(n) {
		if (n & 1)
			res = (m * res) % mod;
		m = (m * m) % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[40] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89,
				107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423,
				9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049,
				216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};
	int n;
	cin >> n;
	cout << (pow(a[n - 1] - 1) + mod - 1) % mod << endl;
	return 0;
}