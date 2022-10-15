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
	vector<int> data(n, 0);
	int x;
	for (int i = 1; i < n; ++i) {
		cin >> x;
		data[i] = data[i - 1] + x;
	}
	int a, b;
	cin >> a >> b;
	cout << data[b - 1] - data[a - 1] << endl;
	return 0;	
}