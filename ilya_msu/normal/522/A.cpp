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

void print(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << "\t";
	cout << endl;
}

void low(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			s[i] = 'a' + (s[i] - 'A');
	}
}

vector<vector<int> > g;

int dfs(int pos, int pr = -1) {
	int res = 0;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		res = max(res, dfs(to, pos));
	}
	return res + 1;
}

void solve() {
	int n;
	cin >> n;
	map<string, int> index;
	index["polycarp"] = 0;
	g.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2 >> s2;
		low(s1);
		low(s2);
		index[s1] = index.size();
		g[index[s1]].push_back(index[s2]);
		g[index[s2]].push_back(index[s1]);
	}
	cout << dfs(0) << endl;


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