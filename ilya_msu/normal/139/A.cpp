#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

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
using std::set;

int main() {
	int n;
	cin >> n;
	vector<int> data(7);
	for (int i = 0; i < 7; ++i)
		cin >> data[i];
	int i = 0;
	while (n > 0) {
		if (i == 7)
			i = 0;
		n -= data[i];
		++i;
	}
	cout << i << endl;
    return 0;
}