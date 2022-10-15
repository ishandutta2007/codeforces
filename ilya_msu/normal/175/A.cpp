#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
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
using std::make_pair;
using std::cos;

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  


int get(string& s, int i, int j) {
	int a1, a2, a3;
	a1 = a2 = a3 = 0;
	for (int k = 0; k < i; ++k) {
		a1 = a1 * 10 + s[k] - '0';
		if (a1 > 1000000)
			return -1;
	}
	if ((s[0] == '0') && (i != 1))
		return -1;
	for (int k = i; k < j; ++k) {
		a2 = a2 * 10 + s[k] - '0';
		if (a2 > 1000000)
			return -1;
	}
	if ((s[i] == '0') && (j != i + 1))
		return -1;
	for (int k = j; k < s.size(); ++k) {
		a3 = a3 * 10 + s[k] - '0';
		if (a3 > 1000000)
			return -1;
	}
	if ((s[j] == '0') && (j != s.size() - 1))
		return -1;
	return a1 + a2 + a3;
}

int main() {
	string s;
	cin >> s;
	int maxi = -1;
	for (int i = 1; i < s.size(); ++i)
		for (int j = i + 1; j < s.size(); ++j)
			maxi = max(maxi, get(s, i, j));
	cout << maxi << endl;
	return 0;
}