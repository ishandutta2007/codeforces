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
	vector<int> depth;
	ll in;
};

ans rec(int pos, const vector<vector<int> >& edges, vector<bool>& used, int k) {
	ans res;
	res.in = 0;
	res.depth.assign(k + 1, 0);
	vector<int> sdepth(k + 1, 0);
	used[pos] = true;
	//vector<bool> oldused = used;
	vector<ans> anss;
	for (int i = 0; i < edges[pos].size(); ++i) {
		if (!used[edges[pos][i]]) {
			anss.push_back(rec(edges[pos][i], edges, used, k));
			for (int j = 0; j < anss.back().depth.size(); ++j)
				sdepth[j] += anss.back().depth[j];
			res.in += anss.back().in;
		}
	}
	ll add = 0;
	for (int i = 0; i < anss.size(); ++i) {
		ans ans1 = anss[i];
		for (int j = 0; (j < ans1.depth.size()) && (j < k - 1); ++j)
				add += ll(ans1.depth[j]) * (ll)(sdepth[k - j - 2] - ans1.depth[k - j - 2]);
	}
	res.in += add / 2;
	res.depth[0] = 1;
	int i = 0;
	res.in += sdepth[k - 1];
	while ((i < k - 1) && (sdepth[i] > 0)) {
		res.depth[i + 1] = sdepth[i];
		++i;
	}
	//res.depth.resize(i);
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int> > edges(n);
	for (int i = 0; i < n - 1; ++i) {
		int first, second;
		scanf("\n%d%d", &first, &second);
		--first;
		--second;
		edges[first].push_back(second);
		edges[second].push_back(first);
	}
	vector<bool> used(n, false);
	cout << rec(0, edges, used, k).in << endl;
	return 0;	
}