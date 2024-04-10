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

struct point {
	int x, y, a;
	point() {
		a = 0;
	}
};

bool comp1(const point& a, const point& b) {
	return ((a.x < b.x) || ((a.x == b.x) && (a.y < b.y)));
}

bool comp2(const point& a, const point& b) {
	return ((a.y < b.y) || ((a.y == b.y) && (a.x < b.x)));
}

int main() {
	int n;
	cin >> n;
	vector<point> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].x >> data[i].y;
	}
	sort(data.begin(), data.end(), comp1);
	for (int i = 1; i < data.size() - 1; ++i) {
		if (data[i].x == data[i - 1].x)
			++data[i].a;
		if (data[i].x == data[i + 1].x)
			++data[i].a;
	}
	int x = 0;
	sort(data.begin(), data.end(), comp2);
	for (int i = 1; i < data.size() - 1; ++i) {
		if (data[i].y == data[i - 1].y)
			++data[i].a;
		if (data[i].y == data[i + 1].y)
			++data[i].a;
		if (data[i].a == 4)
			++x;
	}
	cout << x << endl;
	return 0;
}