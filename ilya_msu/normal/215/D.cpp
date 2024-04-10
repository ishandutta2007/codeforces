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

ll cost(ll t, ll T, ll x, ll c, ll m) {
	ll k = max((ll)0, T - t);
	if (k == 0)
		return c + m * x;
	ll bus = m / k;
	if (m % k != 0)
		++bus;
	ll res1 = bus * c;
	ll res2 = c + m * x;
	return min(res1, res2);
}




int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	ll res = 0;
	int t, T, x, c;
	for (int i = 0; i < n; ++i) {
		cin >> t >> T >> x >> c;
		res += cost(t, T, x, c, m);
		//cout << res << endl;
	}
	cout << res << endl;
	return 0;
}