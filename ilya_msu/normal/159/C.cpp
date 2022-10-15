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
	int n, k;
	string s;
	cin >> k >> s >> n;
	vector<fenvick> f(26, fenvick(k * s.size() + 1));
	vector<vector<int> > data(26);
	int p;
	char c;
	for (int i = 0; i < n; ++i) {
		//cout << i << endl;
		cin >> p >> c;
		int b = c - 'a';
		int l = p, r = k * s.size() + 1, mid;
		while(true) {
			mid = (r + l) / 2;
			int res = mid - f[b].sum(mid);
			//cout << l << "\t" << r << "\t" << res << "\t" << p << endl;
			if ((res == p) && (f[b].get(mid) == 0))
				break;
			if (res < p) 
				l = mid;
			else
				r = mid;
		}
		data[b].push_back(mid);
		f[b].inc(mid, 1);
	}
	for (int i = 0; i < 26; ++i)
		sort(data[i].begin(), data[i].end());
	vector<int> cur(26, 0);
	vector<int> ind(26, 0);
	string ss;
	for (int i = 0; i < k; ++i)
		ss += s;
	for (int i = 0; i < ss.size(); ++i) {
		int b = ss[i] - 'a';
		++cur[b];
		if ((ind[b] < data[b].size()) && (cur[b] == data[b][ind[b]])) {
			++ind[b];
		}
		else
			cout << ss[i];
	}
	cout << endl;
	return 0;
}