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

vector<int> used;
vector<vector<int> > en;



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, b, n;
	cin >> k >> b >> n;
	vector<int> data(n);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	ll z = 0;
	ll res0 = 0;
	for (int i = 0; i < n; ++i)
		if (data[i] == 0)
			++z;
		else {
			res0 += z * (z + 1) / 2;
			z = 0;
		}
		res0 += z * (z + 1) / 2;
	if (b == 0) {
		cout << res0 << endl;
		return 0;
	}
	if (b == k - 1)
		b = 0;
	vector<int> sum(n + 1);
	map<int, int> num;
	num[0] = 1;
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		sum[i] = (sum[i - 1] + data[i - 1]) % (k - 1);
		int x = (sum[i] - b + k - 1) % (k - 1);
		res += num[x];
		if (num.find(sum[i]) == num.end())
			num[sum[i]] = 1;
		else
			++num[sum[i]];// == num[sum[i]] + 1;
	}
	if (b == 0)
		res -= res0;
	cout << res << endl;
	return 0;
}