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
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll> > fl(m);
	for (ll i = 0; i < m; ++i)
		cin >> fl[i].first >> fl[i].second;
	vector<ll> data(n + 1, 1);
	for (ll i = 0; i < m; ++i) {
		for (ll j = i + 1; j < m; ++j) {
			if (fl[i].second == fl[j].second)
				continue;
			ll a, b, c;
			a = fl[j].second - fl[i].second;
			b = -fl[j].first + fl[i].first;
			c = fl[i].second * fl[j].first - fl[j].second * fl[i].first;
			ll count = 0;
			if (a < 0) {
				a = -a;
				b = -b;
				c = -c;
			}
			
			ll xx = (-c) / a;
			if (xx * a != -c)
				continue;
			if ((xx >=1) && (xx <= n)) {
			for (ll k = 0; k < m; ++k)
				if (a * fl[k].first + b * fl[k].second + c == 0)
					++count;
			data[xx] = max(data[xx], count);
			}
		}
	}
	ll res = 0;
	for (ll i = 1; i < n + 1; ++i)
		res += data[i];
	cout << res << endl;
	
	return 0;
}