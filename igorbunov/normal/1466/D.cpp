#include <algorithm>
#include <iostream>
#include <cstdlib>
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
 
using namespace std;

#define int long long
//309810XU
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


vector<int> g[500000];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}
	int ans = 0LL;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		ans += w[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	multiset<int> kek;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)g[i].size() - 1; j++) {
			kek.insert(-w[i]);
		}
	}
	cout << ans << " ";
	for (int i = 0; i < n - 2; i++) {
		ans -= *(kek.begin());
		kek.erase(kek.begin());
		cout << ans << " ";
	}
	cout << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}