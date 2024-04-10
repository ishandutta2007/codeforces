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
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	for (int i1 = 1; i1 < 10; ++i1)
		for (int i2 = 1; i2 < 10; ++i2) 
			for (int i3 = 1; i3 < 10; ++i3) 
				for (int i4 = 1; i4 < 10; ++i4) {
					if ((i1 + i2 == a1) && (i3 + i4 == a2) &&
						(i1 + i3 == b1) && (i2 + i4 == b2) &&
						(i1 + i4 == c1) && (i2 + i3 == c2) &&
						(i1 != i2) && (i1 != i3) && (i1 != i4) && (i2 != i3) && (i2 != i4) && (i3 != i4)) {
							cout << i1 << " " << i2 << endl;
							cout << i3 << " " << i4 << endl;
							return 0;
					}
				}
	cout << -1 << endl;
	return 0;	
}