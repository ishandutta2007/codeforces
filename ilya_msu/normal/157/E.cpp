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

struct ans {
	char c;
	int x;
};

int main() {
	int t;
	vector<vector<int> > data(110, vector<int> (2751, 0));
	int mod = 1000 * 1000 * 1000 + 7;
	for (int i = 0; i < 26; ++i)
		data[0][i] = 1;
	for (int i = 1; i < data.size(); ++i) {
		for (int j = 0; j <= 25 * (i + 1); ++j) {
			for (int k = 0; (k <= j) && (k < 26); ++k)
				data[i][j] = (data[i][j] + data[i - 1][j - k]) % mod;
		}
	}
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;
		int sum = 0;
		for (int j = 0; j < s.size(); ++j)
			sum += s[j] - 'a';
		cout << data[s.size() - 1][sum] - 1 << endl;
	}
	return 0;	
}