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
	vector<int> data;
	int sum = 0;
	cin >> n;
	int dop = 1;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y == 0)
			data.push_back(x);
		else {
			sum += x;
			dop += y - 1;
		}
	}
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	for (int i = 0; (i < data.size()) && (i < dop); ++i)
		sum += data[i];
	cout << sum << endl;

	return 0;
}