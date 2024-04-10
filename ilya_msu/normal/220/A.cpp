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



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	vector<int> sdata = data;
	sort(sdata.begin(), sdata.end());
	int b, e;
	for (b = 0; b < n; ++b) {
		if (data[b] != sdata[b])
			break;
	}
	for (e = n - 1; e >= 0; --e)
		if (data[e] != sdata[e])
			break;
	if (b == n) {
		cout << "YES" << endl;
		return 0;
	}
	swap(data[b], data[e]);
	for (int i = 0; i < n; ++i)
		if (data[i] != sdata[i]) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;

	return 0;
}