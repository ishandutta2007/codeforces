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
	int n;
	cin >> n;
	vector<int> data(n);
	int a, b;
	a = b = -1;
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		if ((a == -1) && (data[i] % 2 == 0))
			a = i;
		if ((b == -1) && (data[i] % 2 == 1))
			b = i;
	}
	int i = 0;
	while ((i == a) || (i == b))
		++i;
	if (data[i] % 2 == 0)
		cout << b + 1 << endl;
	else
		cout << a + 1 << endl;

	
	return 0;
}