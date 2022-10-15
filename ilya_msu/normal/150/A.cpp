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


int main() {
	long long q;
	cin >> q;
	if ((q == 1) || (q == 2)) {
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	long long p = 2;
	while (p * p <= q) {
		if (q % p == 0)
			break;
		++p;
	}
	if (q % p != 0) {
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	long long m = q / p;
	long long i;
	for (i = 2; i * i <= m; ++i) {
		if (m % i == 0) 
			break;
	}
	if ((m % i == 0) && (i != m)) {
		cout << 1 << endl;
		cout << i * p << endl;
	}
	else
		cout << 2 << endl;	
	return 0;	
}