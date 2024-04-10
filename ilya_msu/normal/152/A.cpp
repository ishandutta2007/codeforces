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
	cin >> n >> m;
	vector<bool> data(n, false);
	vector<string> str(n);
	int u = 0;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}
	for (int i = 0; i < m; ++i) {
		int maxi = 0;
		for (int j = 0; j < n; ++j) {
			if (str[j][i] - '0' > maxi)
				maxi = str[j][i] - '0';
		}
		for (int j = 0; j < n; ++j) {
			if (maxi == str[j][i] - '0')
				if (!data[j]) {
					data[j] = true;
					++u;
				}
		}
	}
	cout << u << endl;	
	return 0;	
}