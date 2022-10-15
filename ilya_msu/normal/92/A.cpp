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
	int n, m;
	cin >> n >> m;
	int sum = n * (n + 1) / 2;
	m = m % sum;
	int i = 1;
	while (m >= i) {
		m -= i;
		++i;
	}
	cout << m << endl;
	return 0;	
}