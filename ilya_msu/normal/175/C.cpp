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
	int n;
	cin >> n;
	vector<pair<ll, ll> > figures(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> figures[i].second >> figures[i].first;
		sum += figures[i].second;
	}
	sort(figures.begin(), figures.end());
	int t;
	cin >> t;
	vector<ll> p(t);
	for (int i = 0; i < t; ++i) {
		cin >> p[i];
	}
	p.push_back(sum);
	for (int i = t; i > 0; --i) {
		p[i] -= p[i - 1];
	}
	ll res = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (figures[i].second > p[j]) {
			res += figures[i].first * p[j] * (j + 1);
			figures[i].second -= p[j];
			++j;
		}
		p[j] -= figures[i].second;
		res += figures[i].first * figures[i].second * (j + 1);
	}
	cout << res << endl;
	return 0;
}