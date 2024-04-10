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
	vector<int> p(1000001, 1);
	p[0] = p[1] = 0;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i])
			for (int j = i + i; j < p.size(); j += i)
				p[j] = 0;
	}
	int n;
	cin >> n;
	ll x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ll y = sqrt(0.5 + x);
		if ((y * y == x) && (p[y]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}