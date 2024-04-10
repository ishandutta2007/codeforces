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

vector<int> used;
vector<vector<int> > en;

pii dfs(int pos) {
	pii res(1, 0);
	used[pos] = true;
	for (int i = 0; i < en[pos].size(); ++i) {
		++res.second;
		int to = en[pos][i];
		if (!used[to]) {
			pii c = dfs(to);
			res.first += c.first;
			res.second += c.second;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	used.assign(n, false);
	en.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		en[a].push_back(b);
		en[b].push_back(a);
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			pii c = dfs(i);
			if ((2 * c.first == c.second) && (c.first & 1))
				++res;
		}
	if ((n - res) & 1)
		++res;
	cout << res << endl;
	return 0;
}