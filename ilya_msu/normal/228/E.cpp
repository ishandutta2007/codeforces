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
vector<vector<int> > edge;
vector<vector<int> > anti;
vector<int> g;
bool dfs(int pos, int ind = 0) {
	g[pos] = ind;
	for (int i = 0; i < edge[pos].size(); ++i) {
		int to = edge[pos][i];
		if (g[to] != -1) {
			if (g[to] != ind)
				return false;
		}
		else {
			if (!dfs(to, ind))
				return false;
		}
	}
	for (int i = 0; i < anti[pos].size(); ++i) {
		int to = anti[pos][i];
		if (g[to] != -1) {
			if (g[to] == ind)
				return false;
		}
		else {
			if (!dfs(to, 1 - ind))
				return false;
		}
	}
	return true;	
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	g.assign(n, -1);
	edge.resize(n);
	anti.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		if (c) {
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		else {
			anti[a].push_back(b);
			anti[b].push_back(a);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (g[i] == -1) {
			if (!dfs(i)) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (g[i] == 1)
			ans.push_back(i + 1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}