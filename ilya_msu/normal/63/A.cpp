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
	vector<string> names(n), types(n);
	for (int i = 0; i < n; ++i) {
		cin >> names[i] >> types[i];
	}
	for (int i = 0; i < n; ++i) {
		if (types[i] == "rat")
			cout << names[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		if ((types[i] == "child") || (types[i] == "woman"))
			cout << names[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		if (types[i] == "man")
			cout << names[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		if (types[i] == "captain")
			cout << names[i] << endl;
	}
	return 0;	
}