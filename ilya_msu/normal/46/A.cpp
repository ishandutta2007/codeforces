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
	int n;
	int x = 1;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		x = (x + i);
		if (x > n)
			x -= n;
		cout << x << " ";
	}
	return 0;	
}