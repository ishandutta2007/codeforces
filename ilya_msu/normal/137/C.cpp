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

struct sob {
	int a, b;
	
};

bool operator< (sob a, sob b) {
	return (a.a < b.a);
}

int main() {
    int n;
	cin >> n;
	vector<sob> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].a >> data[i].b;
	}
	sort(data.begin(), data.end());
	int b = 0;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		if (data[i].b > b) {
			b = data[i].b;
			++x;
		}
	}
	cout << n - x << endl;
    return 0;
}