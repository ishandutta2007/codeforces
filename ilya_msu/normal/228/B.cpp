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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;
//const int INF = 1000;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	vector<string> data1(n1);
	for (int i = 0; i < n1; ++i)
			cin >> data1[i];
	cin >> n2 >> m2;
	vector<string> data2(n2);
	for (int i = 0; i < n2; ++i)
			cin >> data2[i];
	int xx = 0, yy = 0;
	int rec = 0;
	for (int x = -n2 - n1 - 10; x <= n2; ++x)
		for (int y = -m2 - m1 - 10; y <= m2; ++y) {
			int sum = 0;
			for (int i = 0; (i < n1); ++i) {
				if ((i + x < 0) || (i + x >= n2))
					continue;
				for (int j = 0; (j < m1); ++j) {
					if ((j + y < 0) || (j + y >= m2))
						continue;
					if ((data1[i][j] == data2[i + x][j + y]) && (data1[i][j] == '1'))
						++sum;
				}
			}
			if (sum > rec) {
				rec = sum;
				xx = x;
				yy = y;
			}
		}
	cout << xx << " " << yy << endl;
	return 0;
}