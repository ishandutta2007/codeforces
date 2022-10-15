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


int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int x = 0;
	for (int i = 1; i < e + 1; ++i) {
		if ((i % a == 0) || (i % b == 0) || (i % c == 0) || (i % d == 0))
			++x;
	}
	cout << x << endl;
	return 0;	
}