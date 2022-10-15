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
	vector<string> data(n);
	char str[30];
	for (int i = 0; i < n; ++i) {
		scanf("\n%s", &str);
		data[i] = str;
	}
	sort(data.begin(), data.end());
	int i = 0;
	while ((i < data[0].size()) && (data[0][i] == data[n - 1][i]))
		++i;
	cout << i << endl;

	return 0;
}