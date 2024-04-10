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
	int ud = 0;
	int n;
	cin >> n;
	int min, max;
	cin >> min;
	max = min;
	int x;
	for (int i = 1; i < n; ++i) {
		cin >> x;
		if (x > max) {
			max = x;
			++ud;
		}
		if (x < min) {
			min = x;
			++ud;
		}
	}
	cout << ud << endl;
	return 0;
}