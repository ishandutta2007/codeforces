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
	string answer;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if ((c >= 'A') && (c <='Z'))
			c = c - 'A' + 'a';
		if ((c == 'a') || (c == 'o') || (c == 'e') || (c == 'i') || (c == 'y') || (c == 'u'))
			continue;
		answer += '.';
		answer += c;
	}
	cout << answer << endl;
	return 0;	
}