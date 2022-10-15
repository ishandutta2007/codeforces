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
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i) {
		cout << (s1[i] != s2[i]);
	}
	cout << endl;
	return 0;	
}