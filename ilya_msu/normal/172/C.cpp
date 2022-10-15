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
	int n, m;
	scanf("%d %d", &n, &m); 
	vector<int> times(n), dist(n), out(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &times[i], &dist[i]);
	int i = 0;
	int time = 0;
	while (i != n) {
		vector<pair<int, int> > stud(min(m, n - i));
		for (int j = 0; (j < m) && (i < n); ++i, ++j) {
			stud[j] = make_pair(dist[i], i);
		}
		time = max(time, times[i - 1]);
		sort(stud.begin(), stud.end());
		int add = 1;
		for (int k = 0; k < stud.size(); ++k) {
			out[stud[k].second] = stud[k].first + time;
			if (k < stud.size() - 1) {
			if (stud[k].first == stud[k + 1].first)
				++add;
			else {
				time += 1 + (add / 2);
				add = 1;
			}
			}
		}
		time += 1 + (add / 2);
		time += stud.back().first * 2;
	}
	for (int i = 0; i < n; ++i)
		cout << out[i] << " ";
	cout << endl;
	return 0;
}