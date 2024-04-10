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






int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	int x;
	cin >> n;
	int r1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		r1 = max(x, r1);
	}
	int p1 = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		p1 = max(p1, x);
	}
	int p2 = 10000;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x;
		p2 = min(p2, x);
	}
	int a, b;
	cin >> a >> b;
	double res = sqrt(1.0 / (1.0 + (double)(a * p2) / (b * p1))) * r1;
	printf("%0.12f\n", res);
	return 0;
}