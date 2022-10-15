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
	int m;
	cin >> m;
	if ((m > 2) && (m % 2 == 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}