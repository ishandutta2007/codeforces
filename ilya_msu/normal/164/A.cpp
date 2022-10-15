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
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &data[i]);
	vector<vector<int> > arcs(n), invArcs(n);
	for (int i = 0; i < m; ++i) {
		int first, second;
		scanf("%d %d", &first, &second);
		--first;
		--second;
		arcs[first].push_back(second);
		invArcs[second].push_back(first);
	}
	vector<bool> used1(n, false);
	queue<int> trav;
	for (int i = 0; i < n; ++i) {
		if (data[i] == 1) {
			trav.push(i);
			used1[i] = true;
		}
	}
	while (!trav.empty()) {
		int cur = trav.front();
		trav.pop();
		for (int i = 0; i < arcs[cur].size(); ++i) {
			if (!used1[arcs[cur][i]]) {
				used1[arcs[cur][i]] = true;
				trav.push(arcs[cur][i]);
			}
		}
	}
	vector<bool> used2(n, false);
	queue<int> trav2;
	for (int i = 0; i < n; ++i) {
		if (data[i] == 2) {
			trav2.push(i);
			used2[i] = true;
		}
	}
	while (!trav2.empty()) {
		int cur = trav2.front();
		trav2.pop();
		for (int i = 0; i < invArcs[cur].size(); ++i) {
			if (!used2[invArcs[cur][i]]) {
				used2[invArcs[cur][i]] = true;
				if (data[invArcs[cur][i]] != 1)
				trav2.push(invArcs[cur][i]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (used1[i] && used2[i])
			cout << 1 << endl;
		else
			cout << 0 << endl;

	return 0;
}