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
	bool c = true;
	for (int i = 1; i < s.size(); ++i)
		c = c && (s[i] >= 'A') && (s[i] <='Z');
	if (!c)
		cout << s;
	else {
		for (int i = 0; i < s.size(); ++i) {
			if ((s[i] >= 'A') && (s[i] <='Z'))
				cout << (char)(s[i] - 'A' + 'a');
			else
				cout << (char)(s[i] - 'a' + 'A');


		}
	}
	cout << endl;

    
    return 0;
}