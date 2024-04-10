#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
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
using std::ios_base;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > data(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &data[i][j]);
	vector<int> str(n), stlb(m);
	for (int i = 0; i < n; ++i)
		str[i] = i;
	for (int i = 0; i < m; ++i)
		stlb[i] = i;
	for (int i = 0; i < k; ++i) {
		char c;
		int x, y;
		scanf("\n%c %d %d", &c, &x, &y);
		--x;
		--y;
		if (c == 'c') {
			swap(stlb[x], stlb[y]);
		}
		if (c == 'r') {
			swap(str[x], str[y]);
		}
		if (c == 'g')
			printf("%d\n", data[str[x]][stlb[y]]);
	}
	return 0;
}