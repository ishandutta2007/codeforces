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
int m;

vector<ll> pr(const vector<ll> a, const vector<ll> b) {
	vector<ll> res(4, 0);
	res[0] = (a[0] * b[0] + a[1] * b[2]) % m;
	res[1] = (a[0] * b[1] + a[1] * b[3]) % m;
	res[2] = (a[2] * b[0] + a[3] * b[2]) % m;
	res[3] = (a[2] * b[1] + a[3] * b[3]) % m;
	return res;
}

vector<ll> pow (vector<ll> matr, ll n) {
	vector<ll> res(4, 0);
	res[0] = res[2] = 1;
	while (n) {
		if (n & 1)
			res = pr(res, matr);
		matr = pr(matr, matr);
		n >>= 1;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll l, r, k;
	cin >> m >> l >> r >> k;
	ll k1 = k;
	ll d;
	while ((k1 < 1e9) && (k1 * k1 < r)) {
		d = r / k1;
		if (d * (k1 - k + 1) >= l)
			break;
		else
			++k1;
	}
	d = r / k1;
	while(true) {
		if (r / d - (l - 1) / d >= k)
			break;
		else
			--d;
	}
	vector<ll> matr(4, 1);
	matr[0] = 0;
	matr = pow(matr, d - 1);
	cout << (matr[0] + matr[1]) % m << endl;
	return 0;
}