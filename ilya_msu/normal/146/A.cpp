#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>

using std::stringstream;
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
using std::random_shuffle;
using std::queue;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool c = true;
	int x = 0;
	for (int i = 0; 2 * i < n; ++i) {
		c = c && ((s[i] == '4') || (s[i] == '7'));
		x += s[i] - '0';
	}
	for (int i = n / 2; i < n; ++i) {
		c = c && ((s[i] == '4') || (s[i] == '7'));
		x -= s[i] - '0';
	}
	if (c && (x == 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}