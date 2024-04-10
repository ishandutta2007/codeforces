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
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> p(n), a(n);
	vector<vector<double> > d1(201, vector<double>(401, 0)), d2(201, vector<double>(401, 0));
	d1[0][k + 200] = 1;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		d2.assign(201, vector<double>(401, 0));
		for (int j = 200; j >= 0; --j) {
			for (int ij = 1; ij < 401; ++ij) {
				if (j < 200) {
					int mest = min(400, ij + a[i]);
					d2[j + 1][mest] += d1[j][ij] * p[i] / 100;
				}
				d2[j][ij] += d1[j][ij] * (100 - p[i]) / 100;
			}
		}
		d1 = d2;
	}
	double res = 0;
	for (int i = l; i < 201; ++i)
		for (int j = 200; j < 401; ++j)
			res += d1[i][j];
	printf("%0.10f\n", res);
	return 0;
}