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

ll f(ll x) {
	ll q = x / 10;
	ll res = q;
	res += min((ll)9, max((ll)0, x));
	int y = x % 10;
	while (x > 9) {
		x /= 10;
	}
	if (y >= x)
		++res;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<pii> data(n);
	vector<int> color(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].first >> data[i].second;
		color[2 * i] = data[i].first;
		color[2 * i + 1] = data[i].second;
	}
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	sort(color.begin(), color.end());
	vector<int> fun;
	int cur = 1;
	for (int i = 1; i < color.size(); ++i) {
		if (color[i] == color[i - 1]) 
			++cur;
		else {
			if (cur * 2 >= n) {
				fun.push_back(color[i - 1]);
				cur = 1;
			}
		}
	}
	if (cur * 2 >= n) {
		fun.push_back(color[2 * n - 1]);
	}
	int mini = n + 1;
	for (int i = 0; i < fun.size(); ++i) {
		int a, b;
		a = b = 0;
		for (int j = 0; j < data.size(); ++j) {
			if (data[j].first == fun[i])
				++a;
			else
				if (data[j].second == fun[i])
					++b;
		}
		if ((a + b) * 2 >= n)
			mini = min(mini, max(0, (n + 1) / 2 - a));
	}
	if (mini == n + 1)
		cout << -1 << endl;
	else
		cout << mini << endl;
	return 0;
}