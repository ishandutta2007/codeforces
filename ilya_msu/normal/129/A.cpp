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
	cin >> n;
	int a, b, x;
	a = b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x % 2 == 0)
			++a;
		else
			++b;
	}
	if (b % 2 == 0)
		cout << a << endl;
	else
		cout << b << endl;
	return 0;	
}