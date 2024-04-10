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

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  



int main() {
	int k;
	cin >> k;
	vector<int> data(12);
	int sum = 0;
	for (int i = 0; i < 12; ++i) {
		cin >> data[i];
		sum += data[i];
	}
	if (sum < k) {
		cout << -1 << endl;
		return 0;
	}
	sort(data.begin(), data.end());
	int sum2 = 0;
	int i = 11;
	while (sum2 < k) {
		sum2 += data[i];
		--i;
	}
	cout << 12 - 1 - i << endl;
	return 0;
}