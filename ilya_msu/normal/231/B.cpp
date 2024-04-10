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
const double eps = 1e-12;
const int INF = 1000 * 1000 + 100;
//const int mod = 1000 * 1000 * 1000 + 7;

 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d, l;
	cin >> n >> d >> l;
	int M = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			M -= 1;
			m -= l;
		}
		else {
			M += l;
			m += 1;
		}
	}
	if ((m > d) || (d > M)) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans(n, 1);
	int sum = n & 1;
	if (d > sum) {
		int i = 0;
		while (d > sum) {
			if (ans[i] < l) {
				++ans[i];
				++sum;
			}
			else
				i += 2;
		}
	}
	else {
		int i = 1;
		while (d < sum) {
			if (ans[i] < l) {
				++ans[i];
				--sum;
			}
			else
				i += 2;
		}
	}
	for (int i = 0 ; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}