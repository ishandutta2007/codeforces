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
const int INF = 1000 * 1000 + 10;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<bool> nn(10, false);
	int m = n;
	while(m) {
		nn[m % 10] = true;
		m /= 10;
	}
	int res = 0;
	for (int x = 1; (x * x <= n) ; ++x) {
		if (n % x == 0) {
			int y = x;
			while(y) {
				if (nn[y % 10]) {
					++res;
					break;
				}
				y /= 10;
			}
			if (x * x < n) {
				y = n / x;
				while(y) {
					if (nn[y % 10]) {
						++res;
						break;
					}
					y /= 10;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}