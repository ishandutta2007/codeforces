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
const double eps = 1e-12;
int mod = 1000 * 1000 * 1000 + 7;

vector<vector<ll> > pr(const vector<vector<ll> >& a, const vector<vector<ll> >& b) {
	int m = a.size();
	vector<vector<ll> > res(m, vector<ll> (m, 0));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < m; ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
	return res;
}


vector<vector<ll> > pow(vector<vector<ll> > a, ll n) {
	int m = a.size();
	vector<vector<ll> > res(m, vector<ll>(m, 0));
	for (int i = 0; i < m; ++i)
		res[i][i] = 1;
	while (n) {
		if (n & 1)
			res = pr(res, a);
		a = pr(a, a);
		n >>= 1;
	}
	return res;
}

int conv(char c) {
	int res = c - 'a';
	if ((res >= 0) && (res < 26))
		return res;
	return c - 'A' + 26;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, k;
	ll n;
	cin >> n >> m >> k;
	if (n == 1) {
		cout << m << endl;
		return 0;
	}
	vector<int> a(m, 1);
	vector<vector<ll> > matr(m, vector<ll> (m, 1));
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		matr[conv(s[0])][conv(s[1])] = 0;
	}
	vector<vector<ll> > r = pow(matr, n - 1);
	ll res = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			res = (res + r[i][j]) % mod;
	cout << res << endl;
	return 0;
}