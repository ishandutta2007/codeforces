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
	sort(s.begin(), s.end());
	//cout << s << endl;

	s.push_back('#');

	vector<pair<char,int>> arr;
	int last = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			arr.push_back(make_pair(s[i - 1], i - last));
			last = i;
		}
	}

	//cout << arr.size() << " ";
	s.pop_back();

	if (arr.size() == 1) {
		for (int i = 0; i < (arr[0].second - 1) / k + 1; i++) {
			cout << arr[0].first;
		}
		cout << endl;
		return;
	}

	if (arr[0].second < k) {
		cout << s[k - 1] << endl;
		return;
	}

	if (arr.size() == 2) {
		if (arr[0].second == k) {
			cout << arr[0].first;
			for (int i = 0; i < (arr[1].second - 1) / k + 1; i++) {
				cout << arr[1].first;
			}
			cout << endl;
		} else {
			for (int i = k - 1; i < n; i++) {
				cout << s[i];
			}
			cout << endl;
		}
		return;
	}

	for (int i = k - 1; i < n; i++) {
		cout << s[i];
	}
	cout << endl;


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