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

typedef long long ll; 
typedef pair<ll, ll> pll;
const double PI = 3.14159265358979323846;  


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i];
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	if (data[k - 1] > 0) {
		int i = k;
		while ((i < n) && (data[i] == data[i - 1]))
			++i;
		cout << i << endl;
	}
	else {
		int i = 0;
		while ((i < n) && (data[i] > 0))
			++i;
		cout << i << endl;
	}	
	return 0;	
}