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


int main() {
	string s;
	cin >> s;
	string s1, s2;
	int i = 0;
	while (s[i] != '.') {
		s1 += s[i];
		++i;
	}
	++i;
	for (int j = i; j < s.size(); ++j)
		s2 += s[j];
	if (s1[s1.size() - 1] == '9') {
		cout << "GOTO Vasilisa." << endl;
		return 0;
	}
	if (s2[0] < '5')
		cout << s1 << endl;
	else {
		++s1[s1.size() - 1];
		cout << s1 << endl;
	}
	return 0;	
}