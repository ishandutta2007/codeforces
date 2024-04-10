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


//#define int long long
#define endl "\n"

vector<vector<int>> t(4000000);


void build(int v, int vl, int vr, vector<int> &arr) {
	t[v].clear();
	if (vr - vl == 1) {
		t[v].push_back(arr[vl]);
	} else {
	    int vm = (vl + vr) / 2;
	    build(v * 2 + 1, vl, vm, arr);
	    build(v * 2 + 2, vm, vr, arr);
		vector<int> arr1 = t[v * 2 + 1];
		vector<int> arr2 = t[v * 2 + 2];
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
			if (t[v * 2 + 1][l] > t[v * 2 + 2][r]) {
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

int cnt(int v, int l, int r, int vl, int vr, int k) {
	if (l >= r) {
		return 0;
	}
	if (l == vl && r == vr) {
		return upper_bound(t[v].begin(), t[v].end(), k) - t[v].begin();
	} else {
		int vm = (vl + vr) / 2;
		int cnt1 = cnt(v * 2 + 1, l, min(r, vm), vl, vm, k);
		int cnt2 = cnt(v * 2 + 2, max(l, vm), r, vm, vr, k);
		return cnt1 + cnt2;
	}
}

vector<int> arr1(1000000);
vector<int> arr2(1000000);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < 1000000; i++) {
    	arr1[i] = 0;
    	arr2[i] = 1000000;
    }
    long long ans = 0LL;
    for (int i = 0; i < n; i++) {
    	int y, l, r;
    	cin >> y >> l >> r;
    	if (l == 0 && r == 1000000) {
    		arr1[y]  = -1000000;
    		ans += 1LL;
    		continue;
    	}
    	if (l == 0) {
    		arr1[y] = -r;
    	} else {
    		arr2[y] = l;
    	}
    }
    vector<pair<int, pair<int, int>>> arr3;
    for (int i = 0; i < m; i++) {
    	int x, l, r;
    	cin >> x >> l >> r;
    	if (l == 0 && r == 1000000) {
    		ans += 1LL;
    	}
    	arr3.push_back(make_pair(x, make_pair(l, r)));
    }
    build(0, 0, 1000000, arr1);
    //return 0;
    for (int i = 0; i < m; i++) {
    	int x = arr3[i].first;
    	int l = arr3[i].second.first;
    	int r = arr3[i].second.second;
    	ans += (long long)cnt(0, l, min(r + 1, 1000000), 0, 1000000, -x);
    }
    for (int i = 0; i < 6; i++) {
        //cout << t[0][i] << " " << arr1[i] << endl;
    }
    build(0, 0, 1000000, arr2);
    for (int i = 0; i < m; i++) {
    	int x = arr3[i].first;
    	int l = arr3[i].second.first;
    	int r = arr3[i].second.second;
    	ans += (long long)cnt(0, l, min(r + 1, 1000000), 0, 1000000, x);
    }
    cout << ans + 1LL;
}