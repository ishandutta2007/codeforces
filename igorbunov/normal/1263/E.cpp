#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
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
#define endl '\n'

int t1[5000000];
int t2[5000000];
int mas[5000000];
 
int MOD = 998244353;
 
void push(int v, int vl, int vr) {
    int vm = (vl + vr) / 2;
    if (v * 2 + 1 < 4000000) {
        mas[v * 2 + 1] += mas[v];
    }
    if (v * 2 + 2 < 4000000) {
        mas[v * 2 + 2] += mas[v];
    }
    t1[v] += mas[v];
    t2[v] += mas[v];
    mas[v] = 0;
}
 
int all_min(int v, int l, int r, int vl, int vr) {
    push(v, vl, vr);
    if (l >= r) {
        return 10000000;
    }
    if (l == vl && r == vr) {
        return t1[v];
    }
    int vm = (vl + vr) / 2;
    int sum1 = all_min(v * 2 + 1, l, min(r, vm), vl, vm);
    int sum2 = all_min(v * 2 + 2, max(l, vm), r, vm, vr);
    return min(sum1, sum2);
}


int all_max(int v, int l, int r, int vl, int vr) {
    push(v, vl, vr);
    if (l >= r) {
        return -1000000;
    }
    if (l == vl && r == vr) {
        return t2[v];
    }
    int vm = (vl + vr) / 2;
    int sum1 = all_max(v * 2 + 1, l, min(r, vm), vl, vm);
    int sum2 = all_max(v * 2 + 2, max(l, vm), r, vm, vr);
    return max(sum1, sum2);
}
void update(int v, int l, int r, int vl, int vr, int val) {
    push(v, vl, vr);
    if (l >= r) {
        return;
    }
    if (l == vl && r == vr) {
        mas[v] += val;
        push(v, vl, vr);
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2 + 1, l, min(r, vm), vl, vm, val);
    update(v * 2 + 2, max(l, vm), r, vm, vr, val);
    t1[v] = min(t1[v * 2 + 1], t1[v * 2 + 2]);
    t2[v] = max(t2[v * 2 + 1], t2[v * 2 + 2]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t;
    map<char, int> cost;
    cost['(']++;
    cost[')']--;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n + 5; i++) {
        s.push_back('a');
    }
    int pos = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'L') {
            pos--;
            pos = max(pos, 0LL);
            if (all_min(0, 0, n, 0, n) >= 0 && all_min(0, n - 1, n, 0, n) == 0) {
                cout << all_max(0, 0, n, 0, n) << " ";
            } else {
                cout << -1 << " ";
            }
            continue;
        }
        if (c == 'R') {
            pos++;
            if (all_min(0, 0, n, 0, n) >= 0 && all_min(0, n - 1, n, 0, n) == 0) {
                cout << all_max(0, 0, n, 0, n) << " ";
            } else {
                cout << -1 << " ";
            }
            continue;
        }
        int mod = cost[c] - cost[s[pos]];
        s[pos] = c;
        update(0, pos, n, 0, n, mod);
        if (all_min(0, 0, n, 0, n) >= 0 && all_min(0, n - 1, n, 0, n) == 0) {
            cout << all_max(0, 0, n, 0, n) << " ";
        } else {
            cout << -1 << " ";
        }
    }
    return 0;
}