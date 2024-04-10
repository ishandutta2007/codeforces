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
	vector<int> data(1001, 0);
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		++data[x];
	}
	x = 0;
	int maxi = 0;
	for (int i = 0; i < data.size(); ++i) 
		if (data[i]) {
			++x;
			maxi = max(maxi, data[i]);
		}
	cout << maxi << " " << x << endl;		
	return 0;	
}