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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

int mod = 1000000007;
vector<vector<int> > c(101, vector<int>(101, 0));
void f() {
	c[0][0] = 1;
	for (int i = 1; i < c.size(); ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	f();
	cin >> n;
	vector<int> d(n + 1, 0);
	d[0] = 1;
	vector<int> a(10);
	for (int i = 0; i < 10; ++i)
		cin >> a[i];
	for(int i = 9; i >= 0; --i) {
		vector<int> newd(n + 1, 0);
		for (int k = 0; k < d.size(); ++k) {
			for (int m = a[i]; (m + k) <= n; ++m) {
				if (m + k > n)
					continue;
				if (i)
					newd[m + k] = ((ll)(newd[m + k]) + (ll)(c[m + k][k]) * (ll)(d[k])) % mod;
				else
					if (k)
						newd[m + k] = ((ll)(newd[m + k]) + (ll)(c[m + k - 1][k - 1]) * (ll)(d[k])) % mod;

			}
		}
		d = newd;
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + d[i]) % mod;
	cout << res << endl;
	return 0;
}