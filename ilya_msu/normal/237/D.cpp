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
vector<vector<int> > g, h;
vector<pii> hhh;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	g.resize(n);
	h.resize(n - 1);
	hhh.resize(n - 1);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		hhh[i] = make_pair(a, b);
		g[a - 1].push_back(i + 1);
		g[b - 1].push_back(i + 1);
	}
	cout << n - 1 << endl;
	for (int i = 0; i + 1 < n; ++i) {
		cout << 2 << " " << hhh[i].first << " " << hhh[i].second << endl;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < g[i].size(); ++j) {
			cout << g[i][0] << " " << g[i][j] << endl;
		}
	}
	return 0;
}