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

signed main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; _++) {
		int n, a, b;
		cin >> n >> a >> b;

		string s;
		cin >> s;
		vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				arr[i] = 1;
			} else {
				arr[i] = 0;
			}
		}

		int now = -1;
		int sz = 0;

		vector<pair<int, pair<int, int>>> arr1;

		for (int i = 0; i < n; i++) {
			if (arr[i] != now) {
				if (now != -1) {
					arr1.push_back(make_pair(now, make_pair(i - sz, i - 1)));
				}

				now = arr[i];
				sz = 1;
			} else {
				sz++;
			}
		}
		arr1.push_back(make_pair(now, make_pair(n - 1 - sz + 1, n - 1)));

		vector<int> arr2(n);

		arr2 = arr;

		for (int i = 1; i < arr1.size() - 1; i++) {

			if (arr1[i].first == 0) {

				int sz1 = arr1[i].second.second - arr1[i].second.first + 1;
				if (b * 2 * (sz1 - 1) <= 2 * a + (sz1 - 1) * b) {
					//cout << arr1[i].second.first << " " << arr1[i].second.second << endl;
					for (int j = arr1[i].second.first; j <= arr1[i].second.second; j++) {
						arr2[j] = 1;
					}
				}
			}
		}

		int ans = (n + 1) * (a + b) - a;

		vector<pair<int, pair<int, int>>> arr4;
		now = -1;
		sz = 0;

		for (int i = 0; i < n; i++) {

			//cout << arr2[i] << " ";
			if (arr2[i] != now) {
				if (now != -1) {
					arr4.push_back(make_pair(now, make_pair(i - sz, i - 1)));
				}

				now = arr[i];
				sz = 1;
			} else {
				sz++;
			}
		}


		arr1.push_back(make_pair(now, make_pair(n - 1 - sz + 1, n - 1)));

		for (int i = 0; i < arr4.size(); i++) {
			if (arr4[i].first == 1) {
				ans += 2 * a;
				ans += (arr4[i].second.second - arr4[i].second.first + 2) * b;
			}
		}
		cout << ans << endl;
	}
}