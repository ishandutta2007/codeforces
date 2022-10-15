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
const long double PI = 3.14159265358979323846;  




int main() {
	int n;
	cin >> n;
	vector<string> players;
	vector<int> bestRes;
	string name;
	int res;
	for (int i = 0; i < n; ++i) {
		cin >> name >> res;
		int j = 0;
		while (j < players.size()) {
			if (players[j] == name) {
				bestRes[j] = max(bestRes[j], res);
				break;
			}
			++j;
		}
		if (j == players.size()) {
			players.push_back(name);
			bestRes.push_back(res);
		}
	}
	/*vector<pair<int, string> > results(players.size());
	for (int i = 0; i < players.size(); ++i) {
		results[i].first = bestRes[i];
		results[i].second = players[i];
	}*/
	vector<int> results = bestRes;
	sort(results.begin(), results.end());
	int all = players.size();
	cout << all << endl;
	for (int i = 0; i < players.size(); ++i) {
		int j = all - 1;
		while (results[j] != bestRes[i])
			--j;
		++j;
		cout << players[i] << " ";
		if (2 * j < all)
			cout << "noob" << endl;
		if ((2 * j >= all) && (5 * j < 4 * all))
			cout << "random" << endl;
		if ((5 * j >= 4 * all) && (10 * j < 9 * all))
			cout << "average" << endl;
		if ((10 * j >= 9 * all) && (100 * j < 99 * all))
			cout << "hardcore" << endl;
		if (100 * j >= 99 * all)
			cout << "pro" << endl;

	}

	return 0;
}