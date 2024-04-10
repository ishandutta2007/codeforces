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


struct node {
	vector<int> children;
	vector<int> parents;
	int preorder;
	int depth;
	int subtree;
};

vector<vector<int>> d;
vector<node> g;
int n;
int num = 0;

int dfs(int pos) {
	g[pos].preorder = num;
	++num;
	if (g[pos].parents[0] == -1) {
		g[pos].depth = 0;
	}
	else {
		g[pos].depth = g[g[pos].parents[0]].depth + 1;
	}
	g[pos].subtree = 1;
	d[g[pos].depth].push_back(num - 1);
	for (int k = 0; k + 1 < g[pos].parents.size(); ++k) {
			if (g[pos].parents[k] == -1)
				break;
			g[pos].parents[k + 1] = g[g[pos].parents[k]].parents[k];
	}
	for (int i = 0; i < g[pos].children.size(); ++i)
		g[pos].subtree += dfs(g[pos].children[i]);
	return g[pos].subtree;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	//cout << n << endl;
	int l = 0;
	while ((1 << l) <= n)
		++l;
	g.resize(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		g[i].parents.assign(l, -1);
		g[i].parents[0] = x - 1;
		if (x)
			g[x - 1].children.push_back(i);
	}
	
	d.resize(n);
	for (int i = 0; i < n; ++i) {
		if (g[i].parents[0] == -1)
			dfs(i);
	}
	int q;
	cin >> q;
	int v, p;
	for (int i = 0; i < q; ++i) {
		cin >> v >> p;
		--v;
		int pp = 1 << (l - 1);
		int p2 = p;
		for (int j = l - 1; j >= 0; --j) {
			if (v == -1)
				break;
			if (p2 >= pp) {
				p2 -= pp;
				v = g[v].parents[j];
			}
			pp >>= 1;
		}
		if ((v == -1) || (p2 > 0)) {
			cout << 0 << " ";
			continue;
		}
		int ourd = g[v].depth + p;
		int lowerb = g[v].preorder;
		int upb = lowerb + g[v].subtree - 1;
		int down = 0, up = d[ourd].size();
		if (d[ourd][0] < lowerb) {
			while (up - down > 1) {
				int mid = (up + down) / 2;
				if (d[ourd][mid] >= lowerb)
					up = mid;
				else
					down = mid;
			}
		}
		else {
			up = down;
		}
		int down2 = 0, up2 = d[ourd].size();
		while (up2 - down2 > 1) {
			int mid = (up2 + down2) / 2;
			if (d[ourd][mid] <= upb)
				down2 = mid;
			else
				up2 = mid;
		}
		cout << down2 - up << " ";
	}
	cout << endl;
	return 0;
}