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
//const int INF = 1000 * 1000 + 100;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int m = 1;
	while(1 << m < n)
		++m;
	vector<vector<int> > tr(m);
	for (int i = 0; i < n; ++i) {
		int j = i;
		int t = 0;
		while (j) {
			if (j & 1)
				tr[t].push_back(i);
			j /= 2;
			++t;
		}
	}
	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		cout << tr[i].size() << " ";
		for (int j = 0; j < tr[i].size(); ++j)
			cout << tr[i][j] + 1 << " ";
		cout << endl;
	}
	return 0;
}