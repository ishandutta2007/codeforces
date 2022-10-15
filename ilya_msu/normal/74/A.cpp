#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>


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


int main() {
	string s, sm;
	int x, maxi = -5000, n;
	cin >> n;
	int p, m, a, b, c, d, e;
	for (int i = 0; i < n; ++i) {
		cin >> s >> p >> m >> a >> b >> c >> d >> e;
		x = 100 * p - 50 * m + a + b + c + d + e;
		if (x > maxi) {
			sm = s;
			maxi = x;
		}
	}
	cout << sm << endl;
	return 0;	
}