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
	int n;
	cin >> n;
	vector<vector<int> > data(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> data[i][j];
	int x = 0;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) {
			int ver = 0;
			for (int k = 0; k < n; ++k)
				ver += data[k][j];
			int hor = 0;
			for (int k = 0; k < n; ++k)
				hor += data[i][k];
			if (ver > hor)
				++x;
		}
	cout << x << endl;	
	return 0;	
}