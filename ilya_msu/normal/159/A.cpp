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
	int n, d;
	cin >> n >> d;
	vector<pair<pair<int,int>,int>> g(n);
	vector<string> names;
	vector<pii> friends;
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		int time;
		cin >> s1 >> s2 >> time;
		int i1 = 0;
		while(i1 < names.size()) {
			if (names[i1] == s1)
				break;
			else
				++i1;
		}
		if (i1 == names.size())
			names.push_back(s1);
		int i2 = 0;
		while(i2 < names.size()) {
			if (names[i2] == s2)
				break;
			else
				++i2;
		}
		if (i2 == names.size())
			names.push_back(s2);
		g[i] = make_pair(make_pair(i1, i2), time);
	}
	for (int i = 0; i < g.size(); ++i) {
		for (int j = i + 1; j < g.size(); ++j)
			if ((g[i].first.first == g[j].first.second) && (g[i].first.second == g[j].first.first) && (g[i].second + d >= g[j].second)
				&& (g[i].second < g[j].second))
				friends.push_back(min(g[i].first, g[j].first));
	}
	sort(friends.begin(), friends.end());
	vector<pii> ans;
	if (!friends.empty())
		ans.push_back(friends[0]);
	for (int i = 1; i < friends.size(); ++i)
		if (friends[i] != friends[i - 1])
			ans.push_back(friends[i]);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << names[ans[i].first] << " " << names[ans[i].second] << endl;		
	return 0;
}