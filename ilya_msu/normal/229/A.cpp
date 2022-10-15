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
const int INF = 1000 * 1000 + 100;
//const int mod = 1000 * 1000 * 1000 + 7;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> data(n);
	vector<int> sum(m, 0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int pos = -1;
		vector<int> dist(m, INF);
		for (int j = 0; j < 2 * m; ++j) {
			int k = j;
			if (k >= m)
				k -= m;
			if (s[k] == '1')
				pos = j;
			if (pos != -1) {
				dist[k] = min(j - pos, dist[k]);
			}
		}
		pos = -1;
		for (int j = 2 * m - 1; j >= 0; --j) {
			int k = j;
			if (k >= m)
				k -= m;
			if (s[k] == '1')
				pos = j;
			if (pos != -1) {
				dist[k] = min(pos - j, dist[k]);
			}
		}
		for (int j = 0; j < m; ++j) {
			sum[j] += dist[j];
		}
	}
	int res = INF;
	for (int i = 0; i < m; ++i)
		res = min(res, sum[i]);
	if (res == INF) 
		cout << -1 << endl;
	else
		cout << res << endl;
	return 0;
}