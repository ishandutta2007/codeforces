#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>

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

typedef long long ll; 


int main() {
	int n, m;
	cin >> n >> m;
	int x0, y0;
	cin >> x0 >> y0;
	int k;
	cin >> k;
	ll sum = 0;
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ac = 2000000000;
		int bc = 2000000000;
		if (a > 0)
			ac = (n - x0) / a;
		if (a < 0)
			ac = (x0 - 1) / (-a);
		if (b > 0)
			bc = (m - y0) / b;
		if (b < 0)
			bc = (y0 - 1) / (-b);
		int c = min(ac, bc);
		x0 = x0 + a * c;
		y0 = y0 + b * c;
		sum += c;
	}
	cout << sum << endl;
	return 0;	
}