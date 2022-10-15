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
	reverse(s1.begin(), s1.end());
	if (s1 == s2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}