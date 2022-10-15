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
using std::sin;
using std::cos;

typedef long long ll; 


int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	//vector<char> zap1(k), zap2(k);
	//vector<int> zap(26, -1);
	char c1, c2;
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		string zap;
		cin >> zap;
		int count1 = 0; 
		int count2 = 0;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == zap[0])
				++count1;
			else
			if (s[j] == zap[1])
				++count2;
			else {
				sum += min(count1, count2);
				count1 = 0;
				count2 = 0;
			}
		}
		sum += min(count1, count2);
	}
	cout << sum << endl;
	return 0;	
}