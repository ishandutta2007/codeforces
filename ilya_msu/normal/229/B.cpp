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
const int INF = 2 * 1000 * 1000 * 1000;
//const int mod = 1000 * 1000 * 1000 + 7;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<pii> > g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	vector<map<int, int> > del(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		vector<int> dd(k);
		for (int j = 0; j < k; ++j) {
			cin >> dd[j];
		}
		if (i == n - 1)
			break;
		dd.push_back(1000000000 + 10);
		for (int j = 0; j < k; ) {
			if (dd[j] + 1 < dd[j + 1]) {
				del[i][dd[j]] = dd[j] + 1;
				++j;
			}
			else {
				int jj = j;
				while(dd[jj] + 1 == dd[jj + 1])
					++jj;
				for (int kk = j; kk < jj + 1; ++kk)
					del[i][dd[kk]] = dd[jj] + 1;
				j = jj + 1;
			}
		}

	}
	vector<int> d(n, INF);
	int d0 = 0;
	if (del[0].find(0) != del[0].end())
		d0 = del[0][0];
	d[0] = d0;
	priority_queue<pii> q;
	q.push(make_pair(-d0, 0));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 		for (int j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			int dd = d[v] + len;
			if (del[to].find(dd) != del[to].end())
				dd = del[to][dd];
			if (dd < d[to]) {
				d[to] = dd;
				q.push(make_pair(-d[to], to));
			}
		}
	}
	if (d[n - 1] == INF) 
		cout << -1 << endl;
	else
		cout << d[n - 1] << endl;
	return 0;
}