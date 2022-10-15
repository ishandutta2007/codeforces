#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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
#include<map>
#include<ctime>

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
using std::map;
using std::clock;
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000;

//int mod = 1000 * 1000 * 1000 + 9;




int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> left(n), right(m), l(m);
	vector<double> ld(n);
	for (int i = 0; i < n; ++i) {
		cin >> left[i];
		ld[i] = sqrt((double)((double)(a) * a + (double)(left[i]) * left[i]));
	}
	for (int i = 0; i < m; ++i)
		cin >> right[i];
	for (int i = 0; i < m; ++i)
		cin >> l[i];
	int ind = 0;
	pii res;
	double dist = 1e9;
	for (int i = 0; i < m; ++i) {
		double xx = (double)(a) * right[i] / b;
		while (ind < n) {
			if (left[ind] < xx)
				++ind;
			else
				break;
		}
		if (ind > 0) {
			double d = l[i] + 
				sqrt((double)((double)(b - a) * (b - a) + (double)(right[i] - left[ind - 1]) * (right[i] - left[ind - 1]))) + ld[ind - 1];
			if (d < dist) {
				dist = d;
				res = make_pair(ind, i + 1);
			}
		}
		if (ind < n) {
			double d = l[i] + 
				sqrt((double)((double)(b - a) * (b - a) + (double)(right[i] - left[ind]) * (right[i] - left[ind]))) + ld[ind];
			if (d < dist) {
				dist = d;
				res = make_pair(ind + 1, i + 1);
			}
		}
	}
	cout << res.first << " " << res.second << endl;	
	return 0;
}