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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  


int main() {
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<int> strsum(n, 0), stsum(m, 0);
	int c;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("\n%d", &c);
			strsum[i] += c;
			stsum[j] += c;
		}
	int optx, opty;
	optx = opty = 0;
	ll mini1 = (ll)(2000000) * 1000 * 1000000000;
	for (int i = 0; i < n + 1; ++i) {
		ll d = 0;
		int r = 2;
		for (int j = i - 1; j >= 0; --j) {
			d += (ll)(r) * (ll)(r) * (ll)(strsum[j]);
			r += 4;
		}
		r = 2;
		for (int j = i; j < n; ++j) {
			d += (ll)(r) * (ll)(r) * (ll)(strsum[j]);
			r += 4;
		}
		if (d < mini1) {
			mini1 = d;
			opty = i;
		}
	}
	ll mini2 = (ll)(2000000) * 1000 * 1000000000;
	for (int i = 0; i < m + 1; ++i) {
		ll d = 0;
		int r = 2;
		for (int j = i - 1; j >= 0; --j) {
			d += (ll)(r) * (ll)(r) * (ll)(stsum[j]);
			r += 4;
		}
		r = 2;
		for (int j = i; j < m; ++j) {
			d += (ll)(r) * (ll)(r) * (ll)(stsum[j]);
			r += 4;
		}
		if (d < mini2) {
			mini2 = d;
			optx = i;
		}
	}
	cout << mini1 + mini2 << endl;
	cout << opty << " " << optx << endl;
 	return 0;

}