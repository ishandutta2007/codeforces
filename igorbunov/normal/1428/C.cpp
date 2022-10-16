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
	string s;
	cin >> s;
	int now = 1;
	char val = s[0];
	vector<pair<int, char>> arr;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != val) {
			arr.push_back(make_pair(now, val));
			//cout << now << " " << val << endl;
			val = s[i];
			now = 0;
		}
		now++;
	}
	arr.push_back(make_pair(now, val));
	//cout << now << " " << val << endl;
	int n = arr.size();
	if (arr.back().second == 'A') {
		arr.pop_back();
		n--;
	}
	int ost = 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i == 0) {
			ost += arr[0].first;
			ans += ost - (ost % 2);
			ost = 0;
			continue;
		}
		if (arr[i].first + ost >= arr[i - 1].first) {
			ans += 2 * arr[i - 1].first;
			ost = ost + arr[i].first - arr[i - 1].first;
		} else {
			ans += 2 * (ost + arr[i].first);
			ost = 0;
		}
		i--;
	}
	ans += ost - (ost % 2);
	cout << s.size() - ans << endl;
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