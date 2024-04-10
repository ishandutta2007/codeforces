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
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s.size() <=10)
			cout << s << endl;
		else {
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
		}
	}
	return 0;	
}