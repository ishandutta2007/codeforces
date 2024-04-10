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

int zer(int a) {
	vector<int> d;
	while (a > 0) {
		d.push_back(a % 2);
		a /= 2;
	}
	while (d.size() < 8)
		d.push_back(0);
	int x = 0;
	for (int i = 0; i < d.size(); ++i) 
		x = 2 * x + d[i];
	return x;
}

int main() {
	char c;
	int p = 0;
	while (scanf("%c", &c)) {
		if (c == '\n')
			return 0;
		int a = c;
		int x = zer(a);

		int v = (p - x + 256) % 256;
		
		x = v;
		p = zer(a);
		cout << x << endl;
		
	}
	return 0;
}