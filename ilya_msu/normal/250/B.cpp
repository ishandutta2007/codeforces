#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:64000000")
//#define _USE_MATH_DEFINES
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
#include<ctime>

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
using std::clock;
using std::nth_element;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
//const int INF = 1000 * 1000;

//int mod = 1000 * 1000 * 1000 + 9;


string restore(string s) {
	string res = "";
	string t = "";
	vector<string> da;
	for (int i = 0; i < s.size(); ++i) {
		/*if ((i == 0) && (s[0] == ':'))
			continue;*/
		if (s[i] != ':')
			t += s[i];
		else {
			if ((i == 1) && (s[i - 1] == ':'))
				continue;
			da.push_back(t);
			t = "";
		}
	}
	if (!t.empty())
		da.push_back(t);
	int n = da.size();
	for (int i = 0; i < da.size(); ++i) {
		if (da[i].empty()) {
			for (int k = n; k < 9; ++k) {
				res += "0000:";
			}
			continue;
		}
		while(da[i].size() < 4)
			da[i] = '0' + da[i];
		res += da[i] + ":";
	}
	res.resize(res.size() - 1);
	return res;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		cout << restore(s) << endl;
	}
	return 0;
}