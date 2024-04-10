#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>

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

typedef long long ll; 


int main() {
	int n, m;
	int mod = 1000000007;
	cin >> n >> m;
	ll res = 1;
	vector<string> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i];
	for (int i = 0; i < m; ++i) {
		int c = 0;
		vector<bool> bu(26, false);
		for (int j = 0; j < n; ++j)
			if (!bu[data[j][i] - 'A']) {
				bu[data[j][i] - 'A'] = true;
				++c;
			}
		res = res * c % mod;
	}
	cout << res << endl;
	return 0;	
}