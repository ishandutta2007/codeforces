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


int main() {
	int n, x;
	cin >> n;
	vector<bool> data(5000, false);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		data[x - 1] = true;
	}
	x = 0;
	for (int i = 0; i < n; ++i)
		if (!data[i])
			++x;
	cout << x << endl;
    return 0;
}