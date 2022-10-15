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
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i) {
		if ((s1[i] >= 'A') && (s1[i] <= 'Z'))
			s1[i] = s1[i] - 'A' + 'a';
		if ((s2[i] >= 'A') && (s2[i] <= 'Z'))
			s2[i] = s2[i] - 'A' + 'a';
	}
	if (s1 < s2)
		cout << -1 << endl;
	else if (s1 == s2)
		cout << 0 << endl;
	else
		cout << 1 << endl;
	return 0;	
}