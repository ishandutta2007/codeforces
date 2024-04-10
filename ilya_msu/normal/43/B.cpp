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

vector<int> zf(string s) {
	vector<int> z(s.size());
	z[0] = 0;
	int r = 0;
	int l = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (r <= i) {
			for (r = i; r < s.size(); ++r)
				if (s[r] != s[r - i])
					break;
			z[i] = r - i;
			--r;
			l = i;
		}
		else {
			int rr;
			z[i] = min(z[i - l], r + 1 - i);
			for (rr = i + z[i]; rr < s.size(); ++rr)
				if (s[rr] != s[rr - i])
					break;
			--rr;
			if (rr > r) {
				l = i;
				r = rr;
			}
		}
	}
	return z;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<int> data(256, 0);
	for (int i = 0; i < s1.size(); ++i)
		if (s1[i] != ' ')
			++data[s1[i]];
	for (int i = 0; i < s2.size(); ++i)
		if (s2[i] != ' ')
			--data[s2[i]];
	for (int i = 0; i < 256; ++i)
		if (data[i] < 0) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}