#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
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
using std::cerr;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	//freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	bool minus = (s[0] == '-');
	if (minus)
		s = s.substr(1, s.size() - 1);
	int k = 0;
	while ((k < s.size()) && (s[k] != '.')) {
		++k;
	}
	string s1 = s.substr(0, k);
	string s2; 
	if (k == s.size())
		s2 = "00";
	else {
		s += "00";
		s2 = s.substr(k + 1, 2);
	}
	if (minus)
		cout << "(";
	cout << "$";
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i];
		if (((s1.size() - 1 - i) % 3 == 0) && (i < s1.size() - 1))
			cout << ",";
	}
	cout << ".";
	cout << s2;
	if (minus)
		cout << ")";
	cout << endl;
 	return 0;
}