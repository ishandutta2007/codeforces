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

string data;
int t;
int house = 0;

bool f(int k) {
	int kcount = k;
	int hcount = 0;
	int last = 0;
	for (int i = 0; i < data.size(); ++i) {
		last = i;
		if (data[i] == 'S')
			++kcount;
		if (data[i] == 'H')
			++hcount;
		if ((hcount >= house) && (kcount >= house))
			break;
	}
	if (kcount < house)
		return false;
	++last;
	if (last > t)
		return false;
	int left = -1;
	int time = 0;
	int sum = k;
	for (int i = 0; i < last; ++i) {
		if (data[i] == 'S')
			++sum;
		if (data[i] == 'H')
			--sum;
		if (left == -1) {
			if (time + last + last - i - 1 <= t)
				return true;
		}
		else {
			if (time + last + last - left - 1 <= t)
				return true;
		}
		if ((sum >= 0) && (left == -1)) 
			continue;
		if ((sum >= 0) && (left != -1)) {
			time += 2 * (i - left);
			left = -1;
		}
		if ((sum < 0) && (left != -1))
			continue;
		if ((sum < 0) && (left == -1))
			left = i;
	}
	return (time + last <= t);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n;
	cin >> n >> t;
	cin >> data;
	int last = 0;
	for (int i = 0; i < data.size(); ++i)
		if (data[i] == 'H') {
			++house;
			last = i;
		}
	if (last + 1 > t) {
		cout << -1 << endl;
		return 0;
	}
	int l = -1, up = n;
	while(up > l + 1) {
		int k = (up + l) / 2;
		if (f(k)) {
			up = k;
		}
		else
			l = k;
	}
	cout << up << endl;
	return 0;
}