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
	ll s, k;
	cin >> s >> k;
	vector<ll> f;
	f.push_back(1);
	f.push_back(1);
	ll x = 1;
	int n = 2;
	while (x < s) {
		x *= 2;
		if (n - k - 1 >= 0)
			x -= f[n - k - 1];
		f.push_back(x);
		++n;
	}
	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		if (s >= f[i]) {
			ans.push_back(f[i]);
			s -= f[i];
		}
		if (s == 0)
			break;
	}
	if (ans.size() == 1)
		ans.push_back(0);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
	return 0;
}