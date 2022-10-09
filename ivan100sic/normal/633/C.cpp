#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int nx[27];
	int t;
} a[1000005];
int nc = 1;

int m;
string dict[100005];

int n;
string s;
int d[10005];
int p[10005];
int w[10005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	s = string(" ") + s;
	d[0] = 1;
	
	cin >> m;
	for (int i=1; i<=m; i++) {
		string s;
		cin >> s;
		dict[i] = s;
		reverse(s.begin(), s.end());
		int y = 0;
		for (char x : s) {
			int c = x & 31;
			if (a[y].nx[c] == 0) {
				a[y].nx[c] = nc++;
			}
			y = a[y].nx[c];
		}
		a[y].t = i;
	}
	
	for (int i = 0; i < n; i++) {
		if (!d[i]) {
			continue;
		}
		int y = 0;
		int j = i + 1;
		while (j <= n) {
			// spusti se
			y = a[y].nx[s[j] & 31];
			if (y == 0) {
				break;
			}
			if (a[y].t && !d[j]) {
				d[j] = 1;
				p[j] = i;
				w[j] = a[y].t;
			}
			j++;
		}
	}

	vector<int> sol;
	{
		int t = n;
		while (t != 0) {
			sol.push_back(t);
			t = p[t];
		}
	}

	vector<string> words;
	for (int x : sol) {
		words.push_back(dict[w[x]]);
	}

	reverse(words.begin(), words.end());
	for (string s : words) {
		cout << s << ' ';
	}
	cout << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}