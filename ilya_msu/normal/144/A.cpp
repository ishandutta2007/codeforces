#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>

using std::next_permutation;
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
	int maxi = 0, mini = 101, imax, imin;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		if (data[i] > maxi) {
			maxi = data[i];
			imax = i;
		}
		if (data[i] <= mini) {
			mini = data[i];
			imin = i;
		}
	}
	int x = imax + n - imin - 1;
	if (imax >= imin)
		--x;
	cout << x << endl;

	
	return 0;	
}