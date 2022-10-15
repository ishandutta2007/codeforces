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
//const int INF = 1000;
vector<vector<int> > data;

struct pos {
	vector<bool> str, stlb;
	bool ans;
	int bad;
	int s;
	pos(int n, int m) {
		str.assign(n, false);
		stlb.assign(m, false);
		//up();
	}
	void up() {
		ans = true;
		s = 0;
		bad = 0;
		for (int i = 0; i < str.size(); ++i) {
			int sum = 0;
			for (int j = 0; j < stlb.size(); ++j)
				if (str[i] == stlb[j])
					sum += data[i][j];
				else
					sum -= data[i][j];
			if (sum < 0) {
				++bad;
				ans = false;
			}
			s += sum;
		}
		for (int j = 0; j < stlb.size(); ++j) {
			int sum = 0;
			for (int i = 0; i < str.size(); ++i)
				if (str[i] == stlb[j])
					sum += data[i][j];
				else
					sum -= data[i][j];
			if (sum < 0) {
				ans = false;
				++bad;
			}
			s += sum;
		}
	}
};

bool operator < (const pos& a, const pos& b) {
	return a.s < b.s;
}

void print(pos ans) {
	int n1 = 0, n2 = 0;
	for (int i = 0; i < ans.str.size(); ++i)
		if (ans.str[i])
			++n1;
	for (int i = 0; i < ans.stlb.size(); ++i)
		if (ans.stlb[i])
			++n2;
	cout << n1 << " ";
	for (int i = 0; i < ans.str.size(); ++i)
		if (ans.str[i])
			cout << i + 1 << " ";
	cout << endl << n2 << " ";
	for (int i = 0; i < ans.stlb.size(); ++i)
		if (ans.stlb[i])
			cout << i + 1 << " ";
	cout << endl;		
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> str(n, 0);
	vector<int> stlb(m, 0);
	pos ans(n, m);
	data.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> data[i][j];
			str[i] += data[i][j];
			stlb[j] += data[i][j];
		}
	}
	while(true) {
		bool c = false;
		for (int i = 0; i < n; ++i) {
			if (str[i] < 0) {
				for (int j = 0; j < m; ++j) {
					stlb[j] -= 2 * data[i][j];
					data[i][j] *= -1;
				}
				str[i] = -str[i];
				ans.str[i] = !ans.str[i];
				c = true;
			}
		}
		for (int j = 0; j < m; ++j) {
			if (stlb[j] < 0) {
				for (int i = 0; i < n; ++i) {
					str[i] -= 2 * data[i][j];
					data[i][j] *= -1;
				}
				stlb[j] = -stlb[j];
				ans.stlb[j] = !ans.stlb[j];
				c = true;
			}
		}
		if (!c)
			break;
	}
	print(ans);	
	return 0;
}