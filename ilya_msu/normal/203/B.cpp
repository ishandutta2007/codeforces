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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

int c[30][30];
 void f() {
	 for (int i = 0; i < 30; ++i)
		 for (int j = 0; j < 30; ++j)
			 c[i][j] = 0;
	 c[0][0] = 1;
	 for (int i = 1; i < 30; ++i) {
		 c[i][0] = c[i][i] = 1;
		 for (int j = 1; j < i; ++j)
			 c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	 }
 }



int main() {
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > data(n, vector<int>(n, 0));
	vector<pii> q(m);
	for (int i = 0; i < m; ++i)
		cin >> q[i].first >> q[i].second;
	int res = -1;
	for (int i = 0; i < m; ++i) {
		for (int k = max(q[i].first - 1, 1); k < min(q[i].first + 2, n); ++k)
			for (int l = max(q[i].second - 1, 1); l < min(q[i].second + 2, n); ++l) {
				++data[k][l];
				if (data[k][l] == 9)
					res = i + 1;
			}
		if (res != -1)
			break;
	}
	cout << res << endl;

	return 0;

}