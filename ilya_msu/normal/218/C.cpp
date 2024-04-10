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

vector<vector<int> > g;
vector<int> used;

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (!used[to])
			dfs(to);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pii> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].first >> data[i].second;
	}
	g.resize(n);
	used.assign(n, false);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if ((data[i].first == data[j].first) || (data[i].second == data[j].second)) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++k;
			dfs(i);
		}
	}
	cout << k - 1 << endl;
	return 0;
}