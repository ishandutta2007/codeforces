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
const long double gamma = 0.57721566490153286060;
const double eps = 1e-12;
//const int INF = 1000 * 1000 + 100;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	int l = 3;
	while (l * (l - 1) * (l - 2) / 6 <= k)
		++l;
	--l;
	int kk = k - l * (l - 1) * (l - 2) / 6;
	int n = 100;
	vector<vector<int> > g(n, vector<int>(n, 0));
	for (int i = 0; i < l; ++i)
		for (int j = i + 1; j < l; ++j)
			g[i][j] = g[j][i] = 1;
	int ind = l;
	while(kk) {
		int m = 2;
		while (m * (m - 1) / 2 <= kk)
			++m;
		--m;
		kk -= m * (m - 1) / 2;
		for (int i = 0; i < m; ++i)
			g[i][ind] = g[ind][i] = 1;
		++ind;
	}
	cout << ind << endl;
	for (int i = 0; i < ind; ++i) {
		for (int j = 0; j < ind; ++j) 
			cout << g[i][j];
		cout << endl;
	}
	return 0;
}