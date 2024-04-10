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
	int n, m;
	cin >> n >> m;
	vector<pii> a(n), b(m);
	for (int i = 0; i < n; ++i) 
		cin >> a[i].second >> a[i].first;
	for (int i = 0; i < m; ++i) 
		cin >> b[i].second >> b[i].first;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0;
	int j = 0;
	int z = 0;
	int k = 0;
	while ((i < n) && (j < m)) {
		if (a[i] == b[j]) {
			++i;
			++j;
			++k;
			continue;
		}
		if (a[i] > b[j]) {
			++j;
		}
		else
			++i;
	}
	i = 0;
	j = 0;
	
	while ((i < n) && (j < m)) {
		if (a[i].first == b[j].first) {
			++i;
			++j;
			++z;
			continue;
		}
		if (a[i] > b[j]) {
			++j;
		}
		else
			++i;
	}
	cout << z << " " << k << endl;

	return 0;
}