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
	string s, s1;
	vector<string> data(10);
	cin >> s;
	for (int i = 0; i < 10; ++i)
		cin >> data[i];
	for (int i = 0; i < 8; ++i) {
		s1 = s.substr(10 * i, 10);
		int j = 0;
		while (data[j] != s1)
			++j;
		cout << j;
	}
	cout << endl;
	return 0;	
}