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

const int INF = 60 * 1000 * 1000 + 5;


int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<vector<int> > >  data(m, vector<vector<int> >(n, vector<int>(n)));
	vector<vector<int> > mini(n, vector<int>(n, 1000001));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) {
				cin >> data[i][j][k];
				//mini[j][k] = min(mini[j][k], data[i][j][k]);
			}
	}
	vector<vector<vector<int> > > dist(n, vector<vector<int> >(n, vector<int> (n, INF)));
	
	for (int l = 0; l < m; ++l)
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					data[l][i][j] = min(data[l][i][j], data[l][i][k] + data[l][k][j]);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) {
				mini[j][k] = min(mini[j][k], data[i][j][k]);
			}
	}
	vector<vector<int> > dd (n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
		dd[i][i] = 0;
	for (int i = 0; i < n; ++i) {
		vector<vector<int> > d = dd;
		for (int k = 0; k < n; ++k)
			for (int l = 0; l < n; ++l) 
				for (int lll = 0; lll < n; ++lll)
					d[k][l] = min(d[k][l], dd[k][lll] + mini[lll][l]);
		dd = d;
		dist[i] = dd;
	}
	for (int i = 0; i < r; ++i) {
		int s, e, k;
		cin >> s >> e >> k;
		--s;
		--e;
		k = min(k, n - 1);
		cout << dist[k][s][e] << endl;
	}
	

	return 0;
}