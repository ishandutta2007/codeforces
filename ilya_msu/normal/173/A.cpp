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


int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int ok(int a, int b) {
	return a / gcd(a, b) * b;
}

int check(char c1, char c2) {
	if (c1 == c2)
		return 0;
	if (c1 == 'R') {
		if (c2 == 'S')
			return 1;
		else
			return -1;
	}
	if (c1 == 'P') {
		if (c2 == 'R')
			return 1;
		else
			return -1;
	}
	if (c1 == 'S') {
		if (c2 == 'P')
			return 1;
		else
			return -1;
	}
}

int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int size1 = s1.size();
	int size2 = s2.size();
	int kr = ok(size1, size2);
	int m1 = 0, m2 = 0;
	for (int i = 0; i < kr; ++i) {
		if (check(s1[i % size1], s2[i % size2]) == 1)
			++m1;
		if (check(s1[i % size1], s2[i % size2]) == -1)
			++m2;
	}
	int q = n / kr;
	m1 = m1 * q;
	m2 = m2 * q;
	for (int i = q * kr; i < n; ++i) {
		if (check(s1[i % size1], s2[i % size2]) == 1)
			++m1;
		if (check(s1[i % size1], s2[i % size2]) == -1)
			++m2;
	}
	cout << m2 << " " << m1 << endl;


	return 0;
}