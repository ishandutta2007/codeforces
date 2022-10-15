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

int f(int x) {
	int res = 0;
	ll u = 1;
	while (x > 0) {
		if (x % 10) {
			res = res + u * (x % 10);
			u *= 10;
		}
		x /= 10;
	}
	return res;
}

int main() {
	int a, b, c, a1, b1, c1;
	cin >> a >> b;
	c = a + b;
	a1 = f(a);
	b1 = f(b);
	c1 = f(c);
	if (a1 + b1 == c1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}