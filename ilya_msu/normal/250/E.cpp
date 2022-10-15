#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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
#include<ctime>

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
using std::clock;
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000;

//int mod = 1000 * 1000 * 1000 + 9;
int pos = 1;
int dir = 1;

ll get(string s1, string s2) {
	if (s2[pos] == '.')
		return 1;
	bool cl, cr;
	cl = cr = false;
	ll res = 0;
	int left, right;
	left = right = pos;
	while (!cl || !cr) {
		if (s2[pos] == '.')
			return res + 1;
		if (s1[pos + dir] == '#') {
			if (dir == 1)
				cr = true;
			else
				cl = true;
			dir *= -1;
			++res;
			continue;
		}
		if (s1[pos + dir] == '+') {
			dir *= -1;
			++res;
			s1[pos - dir] = '.';
			continue;
		}
		if (dir == 1) {
			if (pos != right) {
				res += right - pos;
				pos = right;
				continue;
			}
			++right;
			++pos;
			++res;
			continue;
		}
		if (dir == -1) {
			if (pos != left) {
				res += pos - left;
				pos = left;
				continue;
			}
			--left;
			--pos;
			++res;
			continue;
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<string> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		data[i] = '#' + data[i] + '#';
	}
	ll time = 0;
	for (int i = 0; i < n - 1; ++i) {
		ll x = get(data[i], data[i + 1]);
		if (x == -1) {
			cout << "Never" << endl;
			return 0;
		}
		time += x;
	}
	cout << time << endl;
	return 0;
}