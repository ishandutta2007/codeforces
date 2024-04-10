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
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> size1(n);
	vector<int> size2(m);
	for (int i = 0; i < n; ++i)
		scanf("\n%d", &size1[i]);
	for (int i = 0; i < m; ++i)
		scanf("\n%d", &size2[i]);
	vector<pair<int, int>> para;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while ((j < m) && (size1[i] - x > size2[j]))
			++j;
		if (j == m)
			break;
		if ((size1[i] - x <= size2[j]) && (size1[i] + y >= size2[j])) {
			para.push_back(make_pair(i, j));
			++j;
		}
	}
	cout << para.size() << endl;
	for (int i = 0; i < para.size(); ++i)
		cout << para[i].first + 1 << " " << para[i].second + 1 << endl;	
	return 0;	
}