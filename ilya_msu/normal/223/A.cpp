#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
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
vector<int> sum;

void p(vector<pair<pii, int>>& data, pii a) {
	while(!data.empty()) {
		pii b = data.back().first;
		if ((b.first >= a.first) && (b.second <= a.second))
			data.pop_back();
		else
			break;
	}
	data.push_back(make_pair(a, sum[a.second + 1] - sum[a.first]));
}


int main() {
	std::ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	stack<pair<char, int> > st;
	int res = 0;
	int cur = 0;
	pii ans(0, 0);
	vector<pair<pii, int>> data;
	sum.assign(s.size() + 1, 0);
	for (int i = 1; i < sum.size(); ++i) {
		if (s[i - 1] == '[')
			sum[i] = 1;
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] == '[') || (s[i] == '(')) {
			st.push(make_pair(s[i], i));
			continue;
		}
		if (st.empty()) {
			continue;
		}
		if ((st.top().first == '[') && (s[i] == ']')) {
			ans = make_pair(st.top().second, i);
			p(data, ans);
			st.pop();
			continue;
		}
		if ((st.top().first == '(') && (s[i] == ')')) {
			ans = make_pair(st.top().second, i);
			p(data, ans);
			st.pop();
			continue;
		}
		while (!st.empty())
			st.pop();
		
	}
	if (cur > 0) {
		p(data, ans);
	}
	sort(data.begin(), data.end());
	res = 0;
	cur = 0;
	pii aans;
	for (int i = 0; i < data.size(); ++i) {
		if (i == 0) {
			cur = data[i].second;
			ans = data[i].first;
		}
		else {
			if (ans.second + 1 == data[i].first.first) {
				cur += data[i].second;
				ans.second = data[i].first.second;
			}
			else 
			{
				cur = data[i].second;
				ans = data[i].first;
			}
		}
		if (cur > res) {
			res = cur;
			aans = ans;
		}
	}
	cout << res << endl;
	if (res) {
		for (int i = aans.first; i <= aans.second; ++i)
			cout << s[i];
	}
	cout << endl;
	return 0;
}