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



int main() {
	int n;
	cin >> n;
	vector<int> data(n);
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		data[x - 1] = i + 1;
	}
	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}