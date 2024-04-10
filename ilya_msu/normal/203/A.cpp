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
	int x, t, a, b, da, db;
	cin >> x >> t >> a >> b >> da >> db;
	vector<int> aa(t), bb(t);
	for (int i = 0; i < t; ++i) {
		aa[i] = a;
		a -= da;
	}
	for (int i = 0; i < t; ++i) {
		bb[i] = b;
		b -= db;
	}
	aa.push_back(0);
	bb.push_back(0);
	for (int i = 0; i <= t; ++i)
		for (int j = 0; j <= t; ++j)
			if (aa[i] + bb[j] == x) {
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;	
 	return 0;

}