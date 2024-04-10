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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string need;

	for (int i = 0; i < k - 1; i++) {
		need.push_back('(');
		need.push_back(')');
	}

	for (int i = 0; i < n / 2 - (k - 1); i++) {
		need.push_back('(');
	}

	for (int i = 0; i < n / 2 - (k - 1); i++) {
		need.push_back(')');
	}

	vector<pair<int, int>> ans;

	for (int i = 0; i < n; i++) {
		if (s[i] != need[i]) {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == need[i]) {
					ans.push_back(make_pair(i + 1, j + 1));
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}
		}
	}
	//cout << s << endl;
	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	//cout << need;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	solve();
    }
}