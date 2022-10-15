#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>

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

int tr(char a) {
	if (a == 'T')
		return 10;
	if (a == 'J')
		return 11;
	if (a == 'Q')
		return 12;
	if (a == 'K')
		return 13;
	if (a == 'A')
		return 14;
	return a - '0';
}

bool comp(char a, char b) {
	int x = tr(a), y = tr(b);
	return x < y;
}


int main() {
	char mast;
	cin >> mast;
	string s1, s2;
	cin >> s1 >> s2;
	if ((s1[1] == mast) && (s2[1] != mast)) {
		cout << "YES" << endl;
		return 0;
	}
	if ((s1[1] != mast) && (s2[1] == mast)) {
		cout << "NO" << endl;
		return 0;
	}
	if (s1[1] != s2[1]) {
		cout << "NO" << endl;
		return 0;
	}
	if (comp(s2[0], s1[0]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;	
}