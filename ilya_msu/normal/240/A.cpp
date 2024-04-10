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
//const int INF = 1000 * 1000 + 100;

struct film {
	string name;
	int m, M;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, k;
	cin >> m >> k;
	vector<bool> like(m + 1, false);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		like[a] = true;
	}
	int n;
	int M = 0;
	int mini = 123;
	cin >> n;
	vector<film> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].name;
		int d;
		cin >> d;
		int count = 0;
		int nu = 0;
		int x;
		for (int i = 0; i < d; ++i) {
			cin >> x;
			if (x == 0)
				++nu;
			else
				if (like[x])
					++count;
		}
		data[i].M = min(k, count + nu);
		data[i].m = d - min(d - count, m - k);
		M = max(M, data[i].M);
		mini = min(mini, data[i].M);
	}
	for (int i = 0; i < n; ++i) {
		bool c1 = true, c2 = false;
		for (int j = 0; j < n; ++j) {
			if (j == i)
				continue;
			if (data[j].M > data[i].m)
				c1 = false;
			if (data[j].m > data[i].M)
				c2 = true;
		}
		if (c2)
			cout << 1 << endl;
		else
			if (c1)
				cout << 0 << endl;
			else
				cout << 2 << endl;
	}
	return 0;
}