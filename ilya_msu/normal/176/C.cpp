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


int main() {
	int n, m, x1, x2, y1, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	int d1 = abs(x1 - x2);
	int d2 = abs(y1 - y2);
	if (d1 < d2)
		swap(d1, d2);
	if (d1 > 4) {
		cout << "Second" << endl;
		return 0;
	}
	if (d1 < 4) {
		cout << "First" << endl;
		return 0;
	}
	if (d2 >= 3) {
		cout << "Second" << endl;
		return 0;
	}
	cout << "First" << endl;
	return 0;
}