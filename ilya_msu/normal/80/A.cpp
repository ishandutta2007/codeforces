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
	for (int i = n + 1; i <= m; ++i) {
		bool p = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				p = false;
				continue;
			}
		}
		if ((p) && (i != m)) {
			cout << "NO" << endl;
			return 0;
		}
		if ((!p) && (i == m)) {
			cout << "NO" << endl;
			return 0;
		} 
	}
	cout << "YES" << endl;
	return 0;	
}