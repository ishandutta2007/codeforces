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
const long double PI = 3.14159265358979323846;  

ll obr (int n) {
	vector<int> pow;
	int p = 1000000005;
	while (p > 0) {
		pow.push_back(p % 2);
		p /= 2;
	}
	reverse(pow.begin(), pow.end());
	ll res = n;
	for (int i = 1; i < pow.size(); ++i) {
		res = res * res % 1000000007;
		if (pow[i] == 1)
			res = res * n % 1000000007;
	}
	return res;
}
int main() {
	string start, end;
	int n;
	cin >> start >> end;
	n = start.size();
	vector<bool> shift(n, true);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			shift[i]  = shift[i] && (start[j] == end[(i + j) % n]);
		}
	}
	ll c = 0;
	for (int i = 0; i < n; ++i)
		if (shift[i])
			++c;
	int k;
	cin >> k;
	if (k == 0) {
		if (shift[0])
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	ll sum = 1;
	int i = 0;
	while (i < k) {
		sum = (sum * (n - 1)) % 1000000007;
		++i;
	}
	ll obrn = obr(n);
	
	if (k % 2 == 0) {
		sum = (sum + 1000000006) % 1000000007;
		ll x = sum * obrn % 1000000007;
		ll res = x * c % 1000000007;
		if (shift[0])
			++res;
		cout << res % 1000000007 << endl;

	}
	else {
		sum = (sum + 1) % 1000000007;
		ll x = sum * obrn % 1000000007;
		ll res = c * x % 1000000007;
		if (shift[0])
			res += 1000000006;
		cout << res % 1000000007 << endl;
	}

	return 0;
}