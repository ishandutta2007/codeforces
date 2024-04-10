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
using std::max;


int main() {
    string s;
    cin >> s;
    int x = 1;
    int n = 0;
    char c = s[0];
    for (int i = 1; i < s.size(); ++i) {
		if (s[i] == c)
				++x;
		else {
				if (x > 0) {
						++n;
						x = 0;
				}
				c = s[i];
				++x;
		}
		if (x == 5) {
				++n;
				x = 0;
		}
    }
    if (x > 0)
            ++n;
    cout << n << endl;

    return 0;
}