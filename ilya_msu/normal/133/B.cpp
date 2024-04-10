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
	long long l = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '>')
			l = (l * 16 + 8) % 1000003;
		if (s[i] == '<')
			l = (l * 16 + 9) % 1000003;
		if (s[i] == '+')
			l = (l * 16 + 10) % 1000003;
		if (s[i] == '-')
			l = (l * 16 + 11) % 1000003;
		if (s[i] == '.')
			l = (l * 16 + 12) % 1000003;
		if (s[i] == ',')
			l = (l * 16 + 13) % 1000003;
		if (s[i] == '[')
			l = (l * 16 + 14) % 1000003;
		if (s[i] == ']')
			l = (l * 16 + 15) % 1000003;
	}
	
	cout << l << endl;
	//cout << int(' ') << endl;
	return 0;
}