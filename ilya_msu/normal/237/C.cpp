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


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> d(1000001, 1);
	vector<int> p(1000001, 0);
	p[0] = p[1] = 0;
	for (int i = 2; i < d.size(); ++i) {
		p[i] = p[i - 1];
		if (d[i] == 1) {
			++p[i];
			for (int j = i + i; j < d.size(); j += i)
				d[j] = i;
		}
	}
	int a, b, k;
	int l = -1;
	cin >> a >> b >> k;
	if (p[b] - p[a - 1] < k) {
		cout << -1 << endl;
		return 0;
	}
	l = 0;
	int j = a;
	int i;
	for (i = a; j <= b; ++i) {
		while((j <= b) && (p[j] - p[i - 1] < k)) {
			++j;
		}
		l = max(l, j - i + 1);
	}
	cout << l << endl;

	return 0;
}