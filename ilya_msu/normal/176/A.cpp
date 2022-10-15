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

struct prod {
	int a, b, c;
};

int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, kk;
	cin >> n >> m >> kk;
	string s;
	vector<vector<prod> > data(n, vector<prod>(m));
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			cin >> data[i][j].a >> data[i][j].b >> data[i][j].c;
	}
	ll maxi = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<pair<int, int> > diff(m);
			for (int k = 0; k < m; ++k) {
				diff[k] = make_pair(data[j][k].b - data[i][k].a, data[i][k].c);
			}
			sort(diff.begin(), diff.end());
			reverse(diff.begin(), diff.end());
			int l = 0;
			int tr = 0;
			ll cur = 0;
			while ((l < m) && (tr < kk) && (diff[l].first > 0)) {
				if (tr + diff[l].second < kk) {
					tr += diff[l].second;
					cur += diff[l].first * diff[l].second;
					++l;
				}
				else {
					cur += diff[l].first * (kk - tr);
					break;
				}
			}
			maxi = max(maxi, cur);
		}
	}
	cout << maxi << endl;
	return 0;
}