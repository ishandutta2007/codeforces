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


ll power(ll x, ll p, ll mod) {
	if (x == 0)
		return 0;
	//vector<bool> data(60);
	if (p == 1) {
		return x % mod;
	}
	if (p == 0) {
		/*if (x == 0)
			return 0;
		else*/
			return 1;
	}
	ll y = power(x, p / 2, mod);
    y = y * y % mod;
    if (p % 2 == 1) y = y * x % mod;
    return y;

	/*x = x % mod;
	int in = 0;
	while (p > 0) {
		data[in] = (p % 2 == 1);
		p /= 2;
		++in;
	}
	ll res = x;
	for (int i = in - 2; i >= 0; --i) {
		res = (res * res) % mod;
		if (data[i])
			res = (res * x) % mod;
	}
	return res;*/
}



int main() {
	
	int t;
	//scanf("%d", &t);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ll k, l, r, p;
		//scanf("%I64d %I64d %I64d %I64d", &k, &l, &r, &p);
		cin >> k >> l >> r >> p;
		if (p == 2) {
			if (k % 2 == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
			continue;
		}
		ll multi;
		ll pow1 = power(2, l, p - 1);
		if (pow1 == 0) {
			pow1 = p - 1;
		}

		ll x = power(k, pow1, p);
		if (x % p == 1) {
			multi = power(2, (r - l + 1) % (p - 1), p);
		}
		else {
			ll pow2 = power(2, r - l + 1, p - 1);
			if (pow2 == 0) {
				pow2 = p - 1;
			}
			ll y = power(x, pow2, p);
			multi = (((y + p - 1) % p) * power((x + p - 1) % p, p - 2, p)) % p;
		}
		ll nok = multi;
		if (k % 2 == 1) {
			nok = multi;
			ll del = power(2, (r - l) % (p - 1), p);
			nok = (multi * power(del, p - 2, p)) % p;
		}
		//printf("%I64d\n", nok);
		cout << nok << endl;

	}
	return 0;
}