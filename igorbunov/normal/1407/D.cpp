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
#define push_back emplace_back

vector<vector<pair<int, int>>> t(1200000);


void build(int v, int vl, int vr, vector<int> &arr) {
	t[v].clear();
	if (vr - vl == 1) {
		t[v].push_back(arr[vl], vl);
	} else {
	    int vm = (vl + vr) / 2;
	    build(v * 2 + 1, vl, vm, arr);
	    build(v * 2 + 2, vm, vr, arr);
		vector<pair<int, int>> arr1 = t[v * 2 + 1];
		vector<pair<int, int>> arr2 = t[v * 2 + 2];
		int l = 0;
		int r = 0;
		while (l != arr1.size() || r != arr2.size()) {
			if (l == arr1.size()) {
				t[v].push_back(t[v * 2 + 2][r]);
				r++;
				continue;
			}
			if (r == arr2.size()) {
				t[v].push_back(t[v * 2 + 1][l]);
				l++;
				continue;
			}
			if (t[v * 2 + 1][l].first > t[v * 2 + 2][r].first) {
				t[v].push_back(t[v * 2 + 2][r]);
				r++;
			} else {
				t[v].push_back(t[v * 2 + 1][l]);
				l++;
			}
		}
		//cout << v << " " << t[v].size() << endl << " ";
	}
}

vector<vector<int>> g(300000);

void cnt(int v, int l, int r, int vl, int vr, int k) {
	if (l >= r) {
		return;
	}
	if (l == vl && r == vr) {
		for (int i = 0; i < t[v].size(); i++) {
			if (t[v][i].first > k) {
				break;
			}
			g[k].push_back(t[v][i].second);
			//cout << k << " " << t[v][i].second << endl;
		}
	} else {
		int vm = (vl + vr) / 2;
		cnt(v * 2 + 1, l, min(r, vm), vl, vm, k);
		cnt(v * 2 + 2, max(l, vm), r, vm, vr, k);
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    vector<int> next1(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            next1[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) {
        s.pop();
    }
    vector<int> prev1(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            prev1[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) {
        s.pop();
    }


    vector<int> next2(n, n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] >= arr[s.top()]) {
            next2[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) {
        s.pop();
    }
    vector<int> prev2(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] >= arr[s.top()]) {
            prev2[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) {
        s.pop();
    }

    /*for (int i = 0; i < n; i++) {
        cout << next1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << prev1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << next2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << prev2[i] << " ";
    }
    cout << endl;*/
    build(0, 0, n, prev1);
    for (int i = 0; i < n; i++) {
    	cnt(0, i + 1, min(n, next1[i] + 1), 0, n, i);
    }
    build(0, 0, n, prev2);
    for (int i = 0; i < n; i++) {
    	cnt(0, i + 1, min(n, next2[i] + 1), 0, n, i);
    }
    vector<int> dp(n, 1000000);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (auto u: g[i]) {
            dp[i] = min(dp[i], dp[u] + 1);
        }
    }
    cout << dp[0];

}