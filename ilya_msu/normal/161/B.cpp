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


int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> tabs;
	vector<int> pens;
	int c, t;
	ll sum = 0;
	int mini = 1000 * 1000 * 1000 + 1;
	int mini_index = 0;
	ll tabsum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c >> t;
		if (mini > c) {
			mini = c;
			mini_index = i + 1;
		}
		if (t == 1) {
			tabsum += c;
			tabs.push_back(make_pair(c, i + 1));
		}
		else 
			pens.push_back(i + 1);
		sum += c;
	}
	if (tabs.size() <= k - 1) {
		double ans = sum - (double)(tabsum) / 2;
		printf("%0.1lf\n", ans);
		for (int i = 0; i < tabs.size(); ++i)
			cout << 1 << " " << tabs[i].second << endl;
		for (int i = 0; i < k - 1 - tabs.size(); ++i)
			cout << 1 << " " << pens[i] << endl;
		cout << pens.size() - (k - 1 - tabs.size());
		for (int j = k - 1 - tabs.size(); j < pens.size(); ++j)
			cout << " " << pens[j];
		cout << endl;
		return 0;
	}
	sort(tabs.begin(), tabs.end());
	ll skid = mini;
	for (int i = 0; i < k - 1; ++i)
		skid += tabs[tabs.size() - i - 1].first;
	double ans = sum - (double)(skid) / 2;
	printf("%0.1lf\n", ans);
	for (int i = 0; i < k - 1; ++i)
		cout << 1 << " " << tabs[tabs.size() - i - 1].second << endl;
	cout << n - k + 1 << " ";
	for (int j = k - 1; j < tabs.size(); ++j)
		cout << tabs[tabs.size() - j - 1].second << " ";
	for (int i = 0; i < pens.size(); ++i)
		cout << pens[i] << " ";
	cout << endl;
	return 0;	
}