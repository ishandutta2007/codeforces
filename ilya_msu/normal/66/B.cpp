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
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];		
	}
	int res = 1;
	for (int i = 0; i < n; ++i) {
		int cur = 1;
		int j = i + 1;
		while ((j < n) && (data[j] <= data[j - 1])) {
			++cur;
			++j;
		}
		j = i - 1;
		while ((j > -1) && (data[j] <= data[j + 1])) {
			++cur;
			--j;
		}
		res = max(res, cur);
	}
	cout << res << endl;
	return 0;
}