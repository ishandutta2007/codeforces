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
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<bool> bleft(n), bright(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i)
		bleft[i] = (s[i] == '-');
	cin >> s;
	for (int i = 0; i < n; ++i)
		bright[i] = (s[i] == '-');
	vector<int> left(n, -1), right(n, -1);
	bool ans = false;
	left[0] = 0;
	vector<int> newl, newr;
	newl.push_back(0);
	int t = 1;
	while((!ans) && (!newl.empty() || !newr.empty())) {
		vector<int> newll, newrr;
		for (int i = 0; i < newl.size(); ++i) {
			int cur = newl[i];
			if (cur + k >= n) {
				ans = true;
				break;
			}
			if ((cur - 1 >= t) && (left[cur - 1] == -1) && (bleft[cur - 1])) {
				left[cur - 1] = t;
				newll.push_back(cur - 1);				
			}
			if ((cur + 1 >= t) && (left[cur + 1] == -1) && (bleft[cur + 1])) {
				left[cur + 1] = t;
				newll.push_back(cur + 1);				
			}
			if ((cur + k >= t) && (right[cur + k] == -1) && (bright[cur + k])) {
				right[cur + k] = t;
				newrr.push_back(cur + k);				
			}
		}
		for (int i = 0; i < newr.size(); ++i) {
			int cur = newr[i];
			if (cur + k >= n) {
				ans = true;
				break;
			}
			if ((cur - 1 >= t) && (right[cur - 1] == -1) && (bright[cur - 1])) {
				right[cur - 1] = t;
				newrr.push_back(cur - 1);				
			}
			if ((cur + 1 >= t) && (right[cur + 1] == -1) && (bright[cur + 1])) {
				right[cur + 1] = t;
				newrr.push_back(cur + 1);				
			}
			if ((cur + k >= t) && (left[cur + k] == -1) && (bleft[cur + k])) {
				left[cur + k] = t;
				newll.push_back(cur + k);				
			}
		}
		newl = newll;
		newr = newrr;
		++t;
	}
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
 	return 0;
}