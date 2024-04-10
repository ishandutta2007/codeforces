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
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size()) {
		cout << "NO" << endl;
		return 0;
	}
	vector<int> dif;
	for(int i = 0; i < s1.size(); ++i)
		if (s1[i] != s2[i])
			dif.push_back(i);
	if (dif.size() != 2) {
		cout << "NO" << endl;
		return 0;
	}
	if ((s1[dif[0]] == s2[dif[1]]) && (s1[dif[1]] == s2[dif[0]]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}