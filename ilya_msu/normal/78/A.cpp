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
	char ss1[101], ss2[101], ss3[101];
	string s1, s2, s3;
	gets(ss1);
	gets(ss2);
	gets(ss3);
	s1 = ss1;
	s2 = ss2;
	s3 = ss3;
	
	int x = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if ((s1[i] == 'a') || (s1[i] == 'e') || (s1[i] == 'i') || (s1[i] == 'o') || (s1[i] == 'u'))
			++x;
	}
	if (x != 5) {
		cout << "NO" << endl;
		return 0;
	}
	x = 0;
	for (int i = 0; i < s2.size(); ++i) {
		if ((s2[i] == 'a') || (s2[i] == 'e') || (s2[i] == 'i') || (s2[i] == 'o') || (s2[i] == 'u'))
			++x;
	}
	if (x != 7) {
		cout << "NO" << endl;
		return 0;
	}
	x = 0;
	for (int i = 0; i < s3.size(); ++i) {
		if ((s3[i] == 'a') || (s3[i] == 'e') || (s3[i] == 'i') || (s3[i] == 'o') || (s3[i] == 'u'))
			++x;
	}
	if (x != 5) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;	
}