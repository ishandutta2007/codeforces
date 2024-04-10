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
#include<map>

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
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	string s;
	cin >> n >> k >> s;
	if (k == 2) {
		int n1, n2;
		n1 = n2 = 0;
		string s1, s2;
		s1 = s2 = s;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				s1[i] = 'A';
				s2[i] = 'B';
			}
			else {
				s1[i] = 'B';
				s2[i] = 'A';
			}
			if (s1[i] == s[i])
				++n2;
			else
				++n1;
		}
		if (n1 < n2) {
			cout << n1 << endl;
			cout << s1 << endl;
		}
		else {
			cout << n2 << endl;
			cout << s2 << endl;
		}
		return 0;
	}
	int nn = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			++nn;
			if ((s[i - 1] != 'A') && ((i + 1 == s.size()) || (s[i + 1] != 'A')))
				s[i] = 'A';
			if ((s[i - 1] != 'B') && ((i + 1 == s.size()) || (s[i + 1] != 'B')))
				s[i] = 'B';
			if ((s[i - 1] != 'C') && ((i + 1 == s.size()) || (s[i + 1] != 'C')))
				s[i] = 'C';
		}
	}
	cout << nn << endl;
	cout << s << endl;
	return 0;
}