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
	vector<string> d(5);
	d[0] = "Sheldon";
	d[1] = "Leonard";
	d[2] = "Penny";
	d[3] = "Rajesh";
	d[4] = "Howard";

	cin >> n;
	int k = 1;
	int m = 5;
	while (m < n) {
		k *= 2;
		m += 5 * k;
	}
	cout << d[(n - m + 5 * k - 1) / k] << endl;
	return 0;	
}