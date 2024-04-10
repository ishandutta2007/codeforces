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




int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> data(n), a(k + 1, 0);
	vector<int> f;
	cin >> data[0];
	f.push_back(data[0]);
	for (int i = 1; i < n; ++i) {
		cin >> data[i];
		if (data[i] != f.back())
			f.push_back(data[i]);
	}
	++a[f[0]];
	++a[f.back()];
	for (int i = 1; i + 1 < f.size(); ++i) {
		++a[f[i]];
		if (f[i - 1] == f[i + 1])
			++a[f[i]];
	}
	int res = 1;
	int M = 0;
	for (int i = 1; i <= k; ++i)
		if (a[i] > M) {
			M = a[i];
			res = i;
		}
	cout << res << endl;
	return 0;
}