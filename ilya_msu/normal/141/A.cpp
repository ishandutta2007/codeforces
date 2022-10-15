#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using std::sqrt;

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



int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	vector<int> d1(26, 0);
	for (int i = 0; i < s1.size(); ++i)
		--d1[s1[i] - 'A'];
	for (int i = 0; i < s2.size(); ++i)
		--d1[s2[i] - 'A'];
	for (int i = 0; i < s3.size(); ++i)
		++d1[s3[i] - 'A'];
	bool c = true;
	for (int i = 0; i < d1.size(); ++i)
		c = c && (d1[i] == 0);
	if (c)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

    return 0;
}