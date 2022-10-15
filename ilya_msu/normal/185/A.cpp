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
	ll n;
	vector<int> data;
	cin >> n;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 1) {
		cout << 3 << endl;
		return 0;
	}
	--n;
	while (n > 0) {
		data.push_back(n % 2);
		n /= 2;
	}
	ll mod = 1000000007;
	ll res1 = 2;
	ll res2 = 4;
	for (int i = data.size() - 2; i >= 0; --i) {
		res2 = res2 * res2 % mod;
		res1 = res1 * res1 % mod;

		if (data[i]) {
			res2 = res2 * 4 % mod;
			res1 = res1 * 2 % mod;
			
		}
	}
	cout << (2 * res2 + res1) % mod << endl;
	return 0;
}