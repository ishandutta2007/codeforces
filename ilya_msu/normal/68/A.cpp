#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>

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


int main() {
	vector<int> p(4);
	int a, b;
	int c = 0;
	cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
	b = min(1000, b);
	for (int i = a; i <= b; ++i) {
		sort(p.begin(), p.end());
		int x = 0;
		for (int j = 0; j < 24; ++j) {
			if ((((i % p[0]) % p[1]) % p[2]) % p[3] == i)
				++x;
			next_permutation(p.begin(), p.end());
		}
		if (x >= 7)
			++c;
	}
	cout << c << endl;
	return 0;	
}