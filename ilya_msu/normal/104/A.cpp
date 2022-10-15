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
	if ((n <= 10) || (n > 21 )) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 20) {
		cout << 15 << endl;
		return 0;
	}
	cout << 4 << endl;
	return 0;	
}