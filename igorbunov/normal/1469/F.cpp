#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <random>
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

#define s second
#define f first
#define push_back emplace_back
#define endl "\n"
#define int long long

int n;
pair<int, int> t[4000000];

void push(int v, int size) {
	if(size > 1) {
		t[2 * v + 1].second += t[v].second;
		t[2 * v + 2].second += t[v].second;
	}
	t[v].first += t[v].second * size;
	t[v].second = 0;
}

void build (int a[], int v, int l, int r) {
	if (l == r - 1) {
		t[v].first = a[l];
	} else {
		int m = (l + r) / 2;
		build (a, v * 2 + 1, l, m);
		build (a, v * 2 + 2, m, r);
		t[v].first = t[v * 2 + 1].first + t[v * 2 + 2].first;
	}
}



int all_sum (int v, int l, int r, int vl, int vr) {
	push(v, vr - vl);
	if (l >= r) {
		return 0;
	}
	if (l == vl && r == vr) {
		return t[v].first;
	}
	int vm = (vl + vr) / 2;
	int sum1 = all_sum(v * 2 + 1, l, min(r, vm), vl, vm);
	int sum2 = all_sum(v * 2 + 2, max(l, vm), r, vm, vr);
	return sum1 + sum2;
}

void mas_sum (int v, int l, int r, int vl, int vr, int add) {
	if (l >= r) {
		return;
	}
	if (l == vl && r == vr) {
		t[v].second += add;
		return;
	}
	int vm = (vl + vr) / 2;
	mas_sum(v * 2 + 1, l, min(r, vm), vl, vm, add);
	mas_sum(v * 2 + 2, max(l, vm), r, vm, vr, add);
	t[v].first += add * (r - l);
}

int get_l() {
	int l = 0;
	int r = 1000000;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (all_sum(0, 0, m, 0,  1000000) != 0) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

int get(int k) {
	int l = 0;
	int r = 1000000;
	if (all_sum(0, 0, r, 0, 1000000) < k) {
		return 10000000;
	}
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (all_sum(0, 0, m, 0,  1000000) >= k) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    mas_sum(0, 0, 1, 0, 1000000, 1);
    sort(arr.rbegin(), arr.rend());
    int ans = 10000000;
    for (int i = 0; i < n; i++) {
    	int lol = get_l();
    	mas_sum(0, lol, lol + 1, 0, 1000000, -1);
    	int k1 = arr[i] / 2;
    	int k2 = (arr[i] - 1) / 2;
    	mas_sum(0, lol + 2, lol + 2 + k1, 0, 1000000, 1);
    	mas_sum(0, lol + 2, lol + 2 + k2, 0, 1000000, 1);
    	ans = min(ans, get(k));
    }
    if (ans == 10000000) {
    	cout << -1;
    	return 0;
    }
    cout << ans;

}