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
	int n, k;
	cin >> n >> k;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	vector<bool> used(n, false);
	int q;
	cin >> q;
	int m = n / k;
	double mini = 100, maxi = 0;
	double cur;
	for (int i = 0; i < q; ++i) {
		cur = 0;
		int x;
		for (int j = 0; j < m; ++j) {
			cin >> x;
			cur += data[--x];
			used[x] = true;
		}
		cur /= m;
		maxi = max(maxi, cur);
		mini = min(mini, cur);
	}
	vector<int> a;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			a.push_back(data[i]);
	sort(a.begin(), a.end());
	if (n - m * k != a.size()) {
		cur = 0;
		for (int i = 0; i < m; ++i)
			cur += a[i];
		cur /= m;
		mini = min(mini, cur);
		cur = 0;
		reverse(a.begin(), a.end());
		for (int i = 0; i < m; ++i)
			cur += a[i];
		cur /= m;
		maxi = max(maxi, cur);
	}
	printf("%0.10f %0.10f\n", mini, maxi);
	return 0;
}