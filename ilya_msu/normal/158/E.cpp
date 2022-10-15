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

struct call {
	int start, length;
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<call> calls(n);
	for (int i = 0; i < n; ++i)
		scanf("\n%d%d", &calls[i].start, &calls[i].length);
	vector<int> dp(k + 1, 0);
	int maxi = 0;
	for (int i = 0; i < n; ++i) {
		maxi = max(maxi, calls[i].start - dp[k] - 1);
		for (int j = min(i, k); j >= max(0, k  - (n - 1 - i)); --j) {
			int neud = 0;
			if (calls[i].start - dp[j] > 0)
				neud = calls[i].start + calls[i].length - 1;
			else
				neud = calls[i].length + dp[j];
			int ud = 0;
			if (j > 0)
				ud = dp[j - 1];
			else
				ud = neud;
			dp[j] = min(ud, neud);
		}
	}
	maxi = max(maxi, 86401 - dp[k] - 1);
	cout << maxi << endl;
	return 0;	
}