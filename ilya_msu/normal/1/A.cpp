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
	int m, n, a;
	cin >> m >> n >> a;
	long long x = m / a;
	if (m % a != 0)
		++x;
	long long y = n / a;
	if (n % a != 0)
		++y;
	cout << x * y << endl;
	return 0;	
}