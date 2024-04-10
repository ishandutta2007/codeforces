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
	string s;
	vector<string> data;
	vector<int> nu(2, 0);
	int n;
	cin >> n;
	int x1 = 0, x2 = 0;
	for (int i = 0; i < n; ++i) {
		int j = 0;
		cin >> s;
		while ((j < data.size()) && (s != data[j]))
			++j;
		if (j == data.size())
			data.push_back(s);
		++nu[j];
	}
	if (nu[0] > nu[1])
		cout << data[0] << endl;
	else
		cout << data[1] << endl;
	return 0;	
}