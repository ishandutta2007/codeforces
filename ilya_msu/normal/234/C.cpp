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
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
const int INF = 100 * 1000;


struct ver {
	int sum;
	bool seg;
	int val;
	ver() {
		sum = 0;
		seg = false;
		val = 0;
	}
	ver(int a) {
		sum = a;
		seg = false;
		val = 0;
	}
};

struct segmentTree {
	int n;
	vector<ver> t;
	segmentTree(int nn) {
		t.resize(nn * 4);
		n = nn;
	}
	void build (const vector<int>& a, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = (tl + tr) / 2;
			build (a, v*2, tl, tm);
			build (a, v*2+1, tm+1, tr);
			t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
		}
	}
	int sum (int v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0;
		if (l == tl && r == tr)
			return t[v].sum;
		int tm = (tl + tr) / 2;
		return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
	}

	void update (int v, int tl, int tr, int pos, int new_val) {
		if (tl == tr)
			t[v] = new_val;
		else {
			int tm = (tl + tr) / 2;
			if (t[v].seg == true) {
				update (v * 2, tl, tm, tl, tm, t[v].val);
				update (v * 2 + 1, tm + 1, tr, tm + 1, tr, t[v].val);
				t[v].seg = false;
			}
			
			if (pos <= tm)
				update (v * 2, tl, tm, pos, new_val);
			else
				update (v * 2 + 1, tm + 1, tr, pos, new_val);
			t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
		}
	}
	void update(int v, int tl, int tr, int l, int r, int new_val) {
		if (l > r)
			return;
		if (l == tl && r == tr) {
			t[v].seg = true;
			t[v].val = new_val;
			t[v].sum = (r - l + 1) * new_val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (t[v].seg == true) {
			update (v * 2, tl, tm, tl, tm, t[v].val);
			update (v * 2 + 1, tm + 1, tr, tm + 1, tr, t[v].val);
			t[v].seg = false;
		}
		update(v * 2, tl, tm, l, min(r, tm), new_val);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;

	}
};


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> data(n);
	vector<int> left(n), right(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	if (data[0] >= 0)
		left[0] = 1;
	else
		left[0] = 0;
	for (int i = 1; i < n; ++i)
		left[i] = left[i - 1] + (data[i] >= 0);
	if (data[n - 1] <= 0)
		right[n - 1] = 1;
	else
		right[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i)
		right[i] = right[i + 1] + (data[i] <= 0);
	int sum = n + 12;
	for (int k = 0; k + 1 < n; ++k) {
		sum = min(sum, left[k] + right[k + 1]);
	}
	cout << sum << endl;
	return 0;
}