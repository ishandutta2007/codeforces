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
//const int INF = 1000;
map<int, ll> ans;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i];
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	vector<ll> sum(n + 1, 0);
	for (int i = 1; i < n + 1; ++i)
		sum[i] = sum[i - 1] + data[i - 1];
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int k;
		cin >> k;
		if (ans.find(k) != ans.end()) {
			cout << ans[k] << endl;
			continue;
		}
		ll a = 1;
		ll next = k + 1;
		ll res = 0;
		ll mul = 1;
		ll st = k;
		while(a <= n) {
			st *= k;
			res += mul * (sum[min(next, (ll)n)] - sum[a]);
			a = next;
			next = a + st;
			++mul;
		}
		cout << res << endl;
		ans[k] = res;
	}
	return 0;
}