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
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n - i; ++j)
			cout << "  ";
		for (int j = 0; j < i; ++j)
			cout << j << " ";
		for (int j = i; j > 0; --j)
			cout << j << " ";
		cout << 0 << endl;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < n - i; ++j)
			cout << "  ";
		for (int j = 0; j < i; ++j)
			cout << j << " ";
		for (int j = i; j > 0; --j)
			cout << j << " ";
		cout << 0 << endl;
	}

	return 0;	
}