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

int step(long long a, long long b) {
	int mod = 1000000007;
	long long res = 1;
	for (int i = 0; i < b; ++i) {
		res = res * a % mod;
	}
	return res;
}


int main() {
	int m, n, k;
	cin >> n >> m >> k;
	int mod = 1000000007;
	if (k > n) {
		cout << step(m, n) << endl;
		return 0;
	}
	if (k == n) {
		cout << step(m, (n + 1) / 2) << endl;
		return 0;
	}
	if (k == 1) {
		cout << step(m, n) << endl;
		return 0;
	}
	if (k % 2 == 0) { 
		cout << m << endl;
		//return 0;
	}
	else {
		cout << step(m, 2) << endl;
	}
	return 0;
}