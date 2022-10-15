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
	string s;
	cin >> s;
	int i = 0;
	while ((i < s.size()) && (s[i] != 'h')) {
		++i;
	}
	while ((i < s.size()) && (s[i] != 'e')) {
		++i;
	}
	while ((i < s.size()) && (s[i] != 'l')) {
		++i;
	}
	++i;
	while ((i < s.size()) && (s[i] != 'l')) {
		++i;
	}
	while ((i < s.size()) && (s[i] != 'o')) {
		++i;
	}
	if (i >= s.size())
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;	
}