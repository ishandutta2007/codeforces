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
	//freopen("input.txt", "r", stdin);
	/*ll ress = 0;
	for (ll k = 1; k <= 2 * 100000; ++k) {
		ress += k * (2 * 100000 - k + 1) * (2 * 100000 - k + 1);
		if (ress < 0) {
			cout << k << endl;
			ress = 0;
		}
	}*/

	int n;
	cin >> n;
	vector<vector<int> > data1(26), data2(26);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; ++i) {
		data1[s1[i] - 'A'].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		data2[s2[i] - 'A'].push_back(i);
	}
	long double res = 0;
	ll zn = (ll)(n) * (ll)(n + 1) * (ll)(2 * n + 1) / 6;
	for (int i = 0; i < 26; ++i) {
		int n1 = data1[i].size();
		int n2 = data2[i].size();
		ll sum1 = 0, sum2 = 0;
		for (int j = 0; j < n1; ++j) {
			sum1 += data1[i][j];
		}
		for (int j = 0; j < n2; ++j) {
			sum2 += data2[i][j];
		}
		res += (long double)((ll)(n) * (ll)(n1) * (ll)(n2)) / zn;
		res -= (long double)(sum1) / zn * sum2;
		int k = 0, l = 0;
		data1[i].push_back(10000000);
		data2[i].push_back(10000000);

		while((k < n1) || (l < n2)) {
			if (data1[i][k] < data2[i][l]) {
				res += (long double)((ll)(data1[i][k]) * (ll)(n) * (ll)(n2 - l)) / zn;
				res -= (long double)((ll)(data1[i][k]) * (ll)(l)) / zn;
				++k;
			}
			else {
				res += (long double)((ll)(data2[i][l]) * (ll)(n) * (ll)(n1 - k)) / zn;
				res -= (long double)((ll)(data2[i][l]) * (ll)(k)) / zn;
				++l;
			}
		}

	}
	printf("%0.12f\n", res);
	return 0;
}