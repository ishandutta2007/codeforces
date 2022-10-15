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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	int n, k;
	cin >> n >> k;
	ll cash;
	cin >> cash;
	vector<pii> data(n - 1);
	vector<int> da(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> data[i].first;
		da[i] = data[i].first;
		data[i].second = i;
	}
	
	sort(data.begin(), data.end());
	ll res = 0;
	for (int i = 0; i < k - 1; ++i)
		res += data[n - i - 2].first;
	if (res >= cash) {
		cout << 1 << endl;
		return 0;
	}
	res += data[n - k - 1].first;
	if (res <= cash) {
		cout << n << endl;
		return 0;
	}
	ll x = res - cash;
	int in = n;
	for (int i = 0; i < k; ++i)
		in = min(in, data[n - 2 - i].second);
	int ans = in;
	for (int i = in - 1; i >= 0; --i)
		if (da[i] + x > data[n - k - 1].first)
			ans = i;
	cout << ans + 1 << endl;

	return 0;
}