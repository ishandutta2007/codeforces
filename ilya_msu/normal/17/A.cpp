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

bool pr(int p) {
	for (int i = 2; i < p; ++i)
		if (p % i == 0)
			return false;
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> pp;
	for (int p = 2; p <= n; ++p) {
		if (pr(p))
			pp.push_back(p);
	}
	for (int i = 0; i + 1 < pp.size(); ++i) {
		if ((pp[i] + pp[i + 1] + 1 <= n) && pr(pp[i] + pp[i + 1] + 1))
			--k;
		
	}
	if (k > 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}