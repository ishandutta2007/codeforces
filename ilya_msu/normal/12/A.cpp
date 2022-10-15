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

struct fenvick {
	vector<int> t;
	vector<int> a;
	int n;
	fenvick (int nn) {
		n = nn;
		t.assign (n, 0);
		a.assign(n, 0);
	}
	int get(int i) {
		return a[i];
	}
	int sum (int r) {
		int result = 0;
		for (; r >= 0; r = (r & (r+1)) - 1)
			result += t[r];
		return result;
	}
	void inc (int i, int delta) {
		a[i] += delta;
		for (; i < n; i = (i | (i+1)))
			t[i] += delta;
	}
	int sum (int l, int r) {
		return sum (r) - sum (l-1);
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if ((s1[0] == s3[2]) && (s1[1] == s3[1]) && (s1[2] == s3[0]) && (s2[0] == s2[2]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}