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

const int INF = 100000;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int> > data(n + 2);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		data[i].resize(k);
		for (int j = 0; j < k; ++j)
			cin >> data[i][j];
		sort(data[i].begin(), data[i].end());
		data[i].push_back(INF);
	}
	data[n] = data[0];
	data[n + 1] = data[1];
	for (int i = 1; i < n + 1; ++i) {
		int left = 0;
		int right = 0;
		while(data[i - 1][left] < data[i][0])
			++left;
		while(data[i + 1][right] < data[i][0])
			++right;
		for (int j = 1; j < data[i].size() - 1; ++j) {
			int addl, addr;
			addl = addr = 0;
			while(data[i - 1][left] < data[i][j]) {
				++left;
				++addl;
			}
			while(data[i + 1][right] < data[i][j]) {
				++addr;
				++right;
			}
			if (addl != addr)
				++res;
		}
	}
	cout << res << endl;
	return 0;
}