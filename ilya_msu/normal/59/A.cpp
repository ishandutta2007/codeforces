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
	string s, s1, s2;
	cin >> s;
	int x1, x2;
	s1 = s2 = s;
	x1 = x2 = 0;
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] >= 'A') && (s[i] <= 'Z')) {
			s1[i] = s[i] - 'A' + 'a';
			++x1;
		}
		else {
			s2[i] = s[i] - 'a' + 'A';
			++x2;
		}
	}
	if (x1 <= x2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
	return 0;	
}