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
	string s1, s2;
	cin >> s1 >> s2;
	int x = s1[0] - s2[0];
	int y = s1[1] - s2[1];
	int n = max(abs(x), abs(y));
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		if (x < 0) {
			cout << "R";
			++x;
		}
		if (x > 0) {
			cout << "L";
			--x;
		}
		if (y < 0) {
			cout << "U";
			++y;
		}
		if (y > 0) {
			cout << "D";
			--y;
		}
		cout << endl;
	}
	return 0;
}