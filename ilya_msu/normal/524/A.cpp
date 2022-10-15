#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
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
#include<cstdio>
#include<cassert>
#include<functional>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;




void solve() {
	int m, k;
	cin >> m >> k;
	map<int, int> index;
	vector<int> id;
	vector<vector<int> > ed(2 * m, vector<int>(2 * m, 0));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (index.find(a) == index.end()) {
			index[a] = index.size();
			id.push_back(a);
		}
		if (index.find(b) == index.end()) {
			index[b] = index.size();
			id.push_back(b);
		}
		ed[index[a]][index[b]] = 1;
		ed[index[b]][index[a]] = 1;

	}
	vector<pair<int, vector<int> > > ans(id.size());
	for (int i = 0; i < ans.size(); ++i) {
		ans[i].first = id[i];
		for (int j = 0; j < ans.size(); ++j) {
			if (i == j)
				continue;
			if (ed[i][j])
				continue;
			int fr = 0, count = 0;
			for (int l = 0; l < ans.size(); ++l) {
				if (ed[i][l]) {
					++fr;
					if (ed[l][j])
						++count;
				}
			}
			if (count * 100 >= k * fr)
				ans[i].second.push_back(id[j]);
		}
		sort(ans[i].second.begin(), ans[i].second.end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ": " << ans[i].second.size();
		for (int j = 0; j < ans[i].second.size(); ++j) {
			cout << " " << ans[i].second[j];
		}
		cout << endl;
	}
}

//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();

#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}