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
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s, a, b;
		cin >> s;
		int j = 0;
		while ((s[j] >='A') && (s[j] <= 'Z')) {
			a += s[j];
			++j;
		}
		while ((j < s.size()) && (s[j] <= '9') && (s[j] >= '0')) {
			b += s[j];
			++j;
		}
		if (j == s.size()) {
			int aa = 0;
			for (int k = 0; k < a.size(); ++k)
				aa = aa * 26 + (a[k] - 'A') + 1;
			cout << 'R' << b << 'C' << aa << endl;
			continue;
		}
		string c;
		while ((s[j] >='A') && (s[j] <= 'Z')) {
			c += s[j];
			++j;
		}
		int d = 0;
		while ((j < s.size()) && (s[j] <= '9') && (s[j] >= '0')) {
			d = 10 * d + (s[j] - '0');
			++j;
		}
		string dd;
		while (d > 0) {
			int x = d % 26;
			d /= 26;
			if (x == 0) {
				x = 26;
				--d;
			}
			dd += 'A' + x - 1;
		}
		reverse(dd.begin(), dd.end());
		cout << dd << b << endl;
	}
	return 0;
}