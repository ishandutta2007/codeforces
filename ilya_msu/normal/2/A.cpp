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
	map<string, int> m, mm;
	map<string, int>::iterator it;
	int n;
	cin >> n;
	string s;
	int x;
	int M = 0;
	string w = "";
	vector<string> ss(n);
	vector<int> xx(n);
	for (int i = 0; i < n; ++i) {
		cin >> s >> x;
		ss[i] = s;
		xx[i] = x;
		if (m.find(s) == m.end()) {
			m[s] = x;
		}
		else
			m[s] += x;
	}
	for (it = m.begin(); it != m.end(); ++it) {
		if ((*it).second > M)
			M = (*it).second;
	}
	for (int i = 0; i < n; ++i) {
		s = ss[i];
		x = xx[i];
		if (mm.find(s) == mm.end()) {
			mm[s] = x;
		}
		else
			mm[s] += x;
		if ((mm[s] >= M) && (m[s] == M)) {
			w = s;
			break;
		}
	}
	cout << w << endl;
	return 0;
}