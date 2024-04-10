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
	//freopen("input.txt", "r", stdin);
	int n, r, R;
	cin >> n >> R >> r;
	if (r > R) {
		cout << "NO" << endl;
		return 0;
	}
	if ((r <= R) && (2 * r > R)) {
		if (n == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	double alpha = 2 * asin((double)r / (R - r));
	if (alpha * n <= 2 * PI + 0.0000000001)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}