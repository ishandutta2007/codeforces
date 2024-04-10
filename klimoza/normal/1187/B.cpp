#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string st;
	cin >> st;
	int m;
	cin >> m;
	vector<vector<int>> a(26);
	for (int i = 0; i < n; i++) {
		a[st[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		vector<int> b(26);
		for (char c : t) b[c - 'a']++;
		int maxi = 0;
		for (int i = 0; i < 26; i++) {
			if (b[i] == 0) continue;
			maxi = max(maxi, a[i][b[i] - 1]);
		}
		cout << maxi + 1 << endl;
	}
	//system("pause");
	return 0;
}