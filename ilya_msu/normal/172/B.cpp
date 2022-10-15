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
	ll a, b, m, r;
	cin >> a >> b >> m >> r;
	vector<int> data(m, -1);
	data[r] = 0;
	int t = 0;
	while (true) {
		r = (a * r + b) % m;
		++t;
		if (data[r] == -1)
			data[r] = t;
		else {
			cout << t - data[r] << endl;
			return 0;
		}
	}
	return 0;
}