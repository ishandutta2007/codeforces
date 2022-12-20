#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e9;
const int N = 3e5 + 13;
vector<int> e[N];


void merge_sort(string& log, vector<int>& a, int l, int r) {
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    merge_sort(log, a, l, m);
    merge_sort(log, a, m, r);
    int i = l, j = m, k = l;
    vector<int> b(a.size());
    while (i < m && j < r) {
        if (a[i] < a[j]) {
            log += "0";
            b[k] = a[i];
            i += 1;
        } else {
            log += "1";
            b[k] = a[j];
            j += 1;
        }
        k += 1;
    }
    while (i < m) {
        b[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < r) {
        b[k] = a[j];
        j += 1;
        k += 1;
    }
    for (int p = l; p < r; ++p)
        a[p] = b[p];
}

bool good = 1;


void merge_sort1(string& log, vector<int>& a, int l, int r, int& top) {
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    merge_sort1(log, a, l, m, top);
    merge_sort1(log, a, m, r, top);
    int i = l, j = m, k = l;
    vector<int> b(a.size());
    while (i < m && j < r) {
        if (top == log.size()) {
            good = 0;
            return;
        }
        if (log[top++] == '0') {
            b[k] = a[i];
            i += 1;
        } else {
            b[k] = a[j];
            j += 1;
        }
        k += 1;
    }
    while (i < m) {
        b[k] = a[i];
        i += 1;
        k += 1;
    }
    while (j < r) {
        b[k] = a[j];
        j += 1;
        k += 1;
    }
    for (int p = l; p < r; ++p)
        a[p] = b[p];
}

string sort(vector<int> a) {

    int n = a.size();
    string log;
    merge_sort(log, a, 0, n);
    return log;
}
void solve() {
    int n, k,a, b;
    string s;
    cin >> s;
    for (int n = 1; n <= 1000; ++n) {
        int top = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = i;
        merge_sort1(s, v, 0, v.size(), top);
        if (good && top == s.size()) {
            vector<int> p(n);
            for (int i = 0; i < n; ++i)
                p[v[i]] = i;
            cout << n << endl;
            for (auto x : p)
                cout << x + 1 << ' ';
            return;
        }
    }
}



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    solve();


}