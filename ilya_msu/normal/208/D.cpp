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



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pll> prize(5, make_pair(0, 0));
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < 5; ++i)
		cin >> prize[i].first;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += p[i];
		for (int j = 4; j >= 0; --j) {
			ll q = sum / prize[j].first;
			prize[j].second += q;
			sum -= q * prize[j].first;
		}
	}
	for (int i = 0; i < 5; ++i)
		cout << prize[i].second << " ";
	cout << endl << sum << endl;
	return 0;
}