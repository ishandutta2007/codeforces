#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;


vector<int> ter(int a) {
	vector<int> data;
	while (a > 0) {
		data.push_back(a % 3);
		a = a / 3;
	}
	return data;
}


int main() {
	int a, c;
	vector<int> aa, cc, bb;
	cin >> a >> c;
	aa = ter(a);
	cc = ter(c);
	int size = max(aa.size(), cc.size());
	while(aa.size() < size)
		aa.push_back(0);
	while(cc.size() < size)
		cc.push_back(0);
	bb.resize(size);
	for (int i = 0; i < size; ++i) {
		bb[i] = (cc[i] - aa[i] + 3) % 3;
	}
	long long x = 0;
	for (int i = size - 1; i > -1; --i) {
		x = 3 * x + bb[i];
	}
	cout << x << endl;

	
	return 0;
}