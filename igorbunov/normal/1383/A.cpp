#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

int arr[20][20];

vector<int> g[20];

int now = 0;
vector<bool> used(20);
void dfs(int v) {
	now++;
	used[v] = true;
	for (auto u: g[v]) {
		if (used[u]) {
			continue;
		}
		dfs(u);
	}
}

void solve() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			arr[i][j] = 0;
		}
		used[i] = false;
		g[i].clear();
	}
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int c = a[i] - 'a';
		int d = b[i] - 'a';
		if (d == c) {
			continue;
		}
		if (c > d) {
			cout << -1 << endl;
			return;
		}
		
		arr[c][d]++;
		if (arr[c][d] == 1) {
			//cout << c << " e " << d << endl;
			g[c].push_back(d);
			g[d].push_back(c);
		}
	}
	for (int i = 0; i < 20; i++) {
		now = 0;
		if (!used[i]) {
			dfs(i);
			//cout << now << endl;
			ans += now - 1;
		}
	}
	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}