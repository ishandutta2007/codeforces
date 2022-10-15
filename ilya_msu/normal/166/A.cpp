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
const double PI = 3.14159265358979323846;  



int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> data(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		data[i] = make_pair(-a, b);
	}
	sort(data.begin(), data.end());
	int x = 1;
	int i = k - 1;
	while ((i > 0) && (data[i] == data[i - 1])) {
		--i;
		++x;
	}
	i = k - 1;
	while ((i < n - 1) && (data[i] == data[i + 1])) {
		++i;
		++x;
	}
	cout << x << endl;

	
	return 0;	
}