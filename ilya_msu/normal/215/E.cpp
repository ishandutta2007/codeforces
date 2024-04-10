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

map<ll, ll> ans;

ll f(ll x) {
	if (ans.find(x) != ans.end())
		return ans[x];
	//cout << x << endl;
	ll res = 0;
	vector<ll> data(100, 0);
	for (int n = 1; n < 32; ++n) {
		ll d = ((ll)1 << n) + 1;
		int l = n + 1;
		while ((l < 64) && (d <= x)) {
			ll q = x / d;
			if (q < ((ll)1 << (n - 1)))
				q = ((ll)1 << (n - 1)) - 1;
			if (q >= ((ll)1 << n))
				q = ((ll)1 << n) - 1;
			data[n] += q - ((ll)1 << (n - 1)) + 1 - (f(q) - f(((ll)1 << (n - 1)) - 1));
			d <<= n;
			++d;
			l += n;
		}
		res += data[n];
	}
	ans[x] = res;
	return res;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll l, r;
	cin >> l >> r;
	cout << f(r) - f(l - 1) << endl;
	return 0;
}