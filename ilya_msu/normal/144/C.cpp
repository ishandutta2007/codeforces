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

bool comp(const vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i])
			return false;
	}
	return true;
}


int main() {
	vector<char> s, p;
	vector<int> data(26, 0), data2(26, 0);;
	//int i = 0;
	char c;
	scanf("%c", &c);
	while (((c >= 'a') && (c <= 'z')) || (c == '?')) {
		s.push_back(c);
		scanf("%c", &c);
	}
	int n = 0;
	scanf("%c", &c);
	while ((c >= 'a') && (c <= 'z')) {
		++n;
		++data[c - 'a'];
		scanf("%c", &c);
		//p.push_back(c);
	}
	if (n > s.size()) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] != '?')
			++data2[s[i] - 'a'];
	}
	int x = 0;
	if (comp(data2, data))
		++x;

	for (int i = 0; i + n < s.size(); ++i) {
		if (s[i] != '?')
			--data2[s[i] - 'a'];
		if (s[i + n] != '?')
			++data2[s[i + n] - 'a'];
		if (comp(data2, data))
			++x;
	}
	cout << x << endl;	
	return 0;	
}