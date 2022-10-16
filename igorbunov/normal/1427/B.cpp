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

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int, pair<int, int>>> arr;
	int l = -1;
	bool was = false;
	bool good = false;
	bool wasr = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (!good) {
				l = i;
				good = true;
			}
		}
		if (s[i] == 'W') {
			if (good && wasr) {
				arr.push_back(make_pair(i - 1 - l, make_pair(l, i - 1)));
			}
			good = false;
			wasr = true;
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		//cout << arr[i].first << " " << arr[i].second.first << " " << arr[i].second.second << endl;
		for (int j = arr[i].second.first; j <= arr[i].second.second; j++) {
			if (k) {
				s[j] = 'W';
				k--;
			}
		}
	}
	//cout << endl;
	for (int i = 1; i < n; i++) {
		if (k && s[i] == 'L' && s[i - 1] == 'W') {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (k && s[i] == 'L' && s[i + 1] == 'W') {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (k && s[i] == 'L') {
			s[i] = 'W';
			k--;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			ans++;
			if (i && s[i - 1] == 'W') {
				ans++;
			}
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