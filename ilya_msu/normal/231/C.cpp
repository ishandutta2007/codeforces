#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
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
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;
const int INF = 1000 * 1000 + 100;
//const int mod = 1000 * 1000 * 1000 + 7;

 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	ll k;
	cin >> n >> k;
	vector<int> data(n);
	for (int i = 0; i < n; ++i) 
		cin >> data[i];
	sort(data.begin(), data.end());
	int res = 0, M = 0;
	vector<ll> s(n + 1, 0);
	for (int i = 0; i < n; ++i)
		s[i + 1]  = s[i] + data[i];
	for (int i = 0; i < n; ++i) {
		int l = 1, r = i + 2;
		while(r > l + 1) {
			int x = (l + r) / 2;
			if ((ll)x * data[i] - (s[i + 1] - s[i - x + 1]) <= k)
				l = x;
			else
				r = x;
		}
		if (l > M) {
			M = l;
			res = data[i];
		}
	}
	cout << M << " " << res << endl;
	return 0;
}