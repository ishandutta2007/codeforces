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



vector<vector<int> > g;
vector<bool> used;
vector<vector<int>> comp(3);
vector<int> ncom;


int get(int s, int n) {
	int solve = 0;
	int ans = 0;
	while (solve < n) {
		++ans;
		bool inc = true;
		while (inc) {
			inc = false;
		for (int i = 0; i < comp[s].size(); ++i) {
			int game = comp[s][i];
			if (used[game])
				continue;
			bool cc = true;
			for (int j = 0; j < g[game].size(); ++j) {
				int from = g[game][j];
				if (used[from])
					continue;
				/*if (ncom[from] == s) {
					++solve;
					++ans;
					used[from] = true;
					continue;
				}*/
				cc = false;
				break;
			}
			if (cc) {
				++solve;
				++ans;
				used[game] = true;
				inc = true;
			}
		}
		}
		s = (s + 1) % 3;
	}
	return ans - 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	ncom.resize(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ncom[i] = x - 1;
		comp[x - 1].push_back(i);
	}
	g.resize(n);
	
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		g[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> g[i][j];	
			--g[i][j];
		}
	}
	int res = 10000;
	for (int i = 0; i < 3; ++i) {
		used.assign(n, false);
		res = min(res, get(i, n));
	}
	cout << res << endl;
	return 0;
}