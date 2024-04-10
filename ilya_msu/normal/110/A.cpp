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
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i < s.size(); ++i)
		if ((s[i] == '4') || (s[i] == '7'))
			++x;
	if ((x == 4) || (x == 7))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;	
}