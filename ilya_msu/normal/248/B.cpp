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
const long double eps = 1e-8;
const int INF = 1000 * 1000 + 10;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n < 3) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << 210 << endl;;
		return 0;
	}
	string s = "1";
	while(s.size() + 3 < n)
		s += "0";
	n = n % 6;
	if (n == 0) 
		s += "170";
	if (n == 1) 
		s += "020";
	if (n == 2) 
		s += "200";
	if (n == 3) 
		s += "110";
	if (n == 4) 
		s += "050";
	if (n == 5) 
		s += "080";
	cout << s << endl;
	return 0;
}