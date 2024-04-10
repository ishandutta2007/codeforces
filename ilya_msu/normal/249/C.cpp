#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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
#include<ctime>

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
using std::clock;
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000;

//int mod = 1000 * 1000 * 1000 + 9;

ll cc[1000][10];
void init() {
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 10; ++j)
			cc[i][j] = 0;
}

ll c(int n, int k) {
	if (k > n)
		return 0;
	if (cc[n][k] != 0)
		return cc[n][k];
	ll res = 1;
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	cc[n][k] = res;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	init();
	int n;
	cin >> n;
	vector<double> p(n, 0.0);
	double sum = 0.0;
	vector<vector<double> > data(n);
	vector<int> a(n), all(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) {
			sum += 1.0;
			p[i] = 1;
		}
		data[i].assign(a[i] + 1, 0.0);
		data[i][a[i]] = 1.0;
		all[i] = a[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v, k;
		cin >> u >> v >> k;
		--u;
		--v;
		//tron[v] += k;
		vector<double> pp(a[u] + 1, 0);
		for (int j = 0; j < pp.size(); ++j) {
			for (int l = 0; l <= k; ++l) {
				if (l + j >= pp.size())
					continue;
				pp[j] += data[u][l + j] * c(l + j, l) * c(all[u] - l - j, k - l) / c(all[u], k);
			}
		}
		all[u] -= k;
		sum -= p[u];
		sum += pp[0];
		p[u] = pp[0];
		data[u] = pp;
		all[v] += k;
		printf("%0.12f\n", sum);
	}
	return 0;
}