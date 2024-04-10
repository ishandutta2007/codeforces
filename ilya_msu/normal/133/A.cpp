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

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	if ((s[i] == 'H') || (s[i] == 'Q') || (s[i] == '9')) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	//cout << int(' ') << endl;
	return 0;
}