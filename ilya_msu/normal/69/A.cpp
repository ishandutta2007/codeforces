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
	int x, y, z, a, b, c;
	x = y = z = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}
	if ((x == 0) && (y == 0) && (z == 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}