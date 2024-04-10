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

struct pair {
	int abs, sign;
	bool operator < (pair& rhs) {
		return (abs < rhs.abs) || ((abs == rhs.abs) && (sign < rhs.sign));
	}
};



int main() {
	int n;
	cin >> n;
	vector<pair> data(n);
	for (int i = 0; i < n; ++i) {
		pair p;
		int x;
		cin >> x;
		p.abs = abs(x);
		if (p.abs == 0)
			p.sign = 0;
		else
			p.sign = x / p.abs;
		data[i] = p;
	}
	sort(data.begin(), data.end());
	long long answer = 0;
	long long zero = 0;
	long long plus = 0;
	long long minus = 0;
	int abs = 0;
	for (int i = 0; i < n; ++i) {
		if (data[i].abs == 0) {
			++zero;
			continue;
		}
		if (data[i].abs == abs) {
			if (data[i].sign == 1)
				++plus;
			if (data[i].sign == -1)
				++minus;
		}
		else {
			abs = data[i].abs;
			answer += plus * minus;
			plus = minus = 0;
			if (data[i].sign == 1)
				++plus;
			if (data[i].sign == -1)
				++minus;
		}
	}
	answer += zero * (zero - 1) / 2;
	answer += plus * minus;
	cout << answer << endl;
	return 0;
}