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
const long double PI = 3.14159265358979323846;  


int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);
	}
	vector<int> ans(n);
	vector<vector<int> > plus(n);
	for (int i = 0; i < n; ++i)
		plus[i].push_back(i);
	vector<int> step;
	int st = 1;
	while (st < n) {
		step.push_back(st);
		st *= 2;
	}
	for (int i = 0; i < n; ++i) {
		int j = step.size() - 1;
		int up = i;
		while (up < n - 1) {
			up += step[j];
			while (up >= n) {
				up -= step[j];
				--j;
				up += step[j];
			}
			plus[up].push_back(i);
			--j;
		}
	}
	ll res = 0;
	for (int k = 0; k < n - 1; ++k) {
		for (int i = 0; i < plus[k].size(); ++i)
			res += data[plus[k][i]];
		cout << res << endl;
	}
	return 0;
}