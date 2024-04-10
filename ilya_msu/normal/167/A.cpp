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
	int n, d, a;
	cin >> n >> a >> d;
	vector<double> time(n);
	int t, v;
	for (int i = 0; i < n; ++i) {
		scanf("\n%d %d", &t, &v);
		if ((ll)(v) * v > (ll)(2 * a) * d)
			time[i] = sqrt((double)(2 * d) / a) + t;
		else
			time[i] = (double)(d) / v + (double)(v) / (2 * a) + t;
	}
	double maxTime = 0.0;
	for (int i = 0; i < n; ++i) {
		maxTime = max(maxTime, time[i]);
		printf("%0.10f\n", maxTime);
	}
	return 0;
}