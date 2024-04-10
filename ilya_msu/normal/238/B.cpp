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
const int INF = 100 * 1000;

int mod = 1000 * 1000 * 1000 + 9;

int pow(int n) {
	ll res = 1;
	ll m = 2;
	while(n) {
		if (n & 1)
			res = (res * m) % mod;
		m = (m * m) % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n, h;
	cin >> n >> h;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> num(n, 1);
	num[a[0].second] = 2;
	int x = 0;
	if (n > 2) {
		int m = min(a[0].first + a[1].first + h, a[1].first + a[2].first);
		int M = max(a[0].first + a[n - 1].first + h, a[n - 1].first + a[n - 2].first);
		x = M - m;
	}
	int y = a[n - 1].first + a[n - 2].first - a[0].first - a[1].first;
	if (y < x) {
		cout << y << endl;
		for (int i = 0; i < n; ++i)
			cout << 1 << " ";
		cout << endl;
		return 0;
	}

	cout << x << endl;
	for (int i = 0; i < n; ++i)
		cout << num[i] << " ";
	cout << endl;


	return 0;
}