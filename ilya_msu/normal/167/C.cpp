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

string rec(ll a, ll b) {
	if (a == 0)
		return "Second";
	if (b % a == 0)
		return "First";
	if (rec(b % a, a) == "Second")
		return "First";
	if (a % 2 == 1) {
	ll sum = 0;
	while (b > 0) {
		b /= a;
		sum += (b % a);
	}
	if ((sum % 2) == 1)
		return "Second";
	return "First";
	}
	else {
		b /= a;
		if ((b / (a + 1) + b) % 2 == 0)
			return "First";
		else
			return "Second";
	}
}


int main() {
	int t;
	ll a, b;
	cin >> t;
	vector<string> ans(t);
	for (int i = 0; i < t; ++i) {
		cin >> a >> b;
		if (b < a)
			swap(a, b);
		ans[i] = rec(a, b);
	}
	for (int i = 0; i < t; ++i)
		cout << ans[i] << endl;
	return 0;
}