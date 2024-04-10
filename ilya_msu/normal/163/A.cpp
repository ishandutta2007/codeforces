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
const double PI = 3.14159265358979323846;  



int main() {
	int mod = 1000000007;
	string s, t;
	cin >> s >> t;
	vector<ll> l(s.size() + 1, 1);
	//l[0] = 1;
	for (int i = 0; i < t.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			if (s[s.size() - j - 1] == t[i])
				l[s.size() - j] = (l[s.size() - j - 1] + l[s.size() - j]) % mod;
		}
	}
	ll sum = mod - s.size();
	for (int i = 1; i < l.size(); ++i)
		sum = (sum + l[i]) % mod;
	cout << sum << endl;


	
	return 0;	
}