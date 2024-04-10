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
const long double PI = 3.14159265358979323846;  


int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> data(5, 0);
	char s1[5];
	gets(s1);
	for (int i = 0; i < n; ++i) {
		gets(s1);
		string s(s1);
		if (s == "UL")
			++data[0];
		if (s == "UR")
			++data[1];
		if (s == "DL")
			++data[2];
		if (s == "DR")
			++data[3];
		if (s == "ULDR")
			++data[4];
	}
	int x = n + data[4];
	ll res = data[0] + data[3] + data[4] + 1;
	res = res * (data[1] + data[2] + data[4] + 1);
	cout << res << endl;
	return 0;
}