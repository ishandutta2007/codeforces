#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 100005;

int n;
int a[MAXN];
vi v;

bool check (int x) {
    if (2 * x + 1 > n) return 0;
    v.clear();
    int lo = 0, hi = n - 1 - x;
    for (int i = 0; i < x; i++) {
        v.push_back(a[hi]);
        v.push_back(a[lo]);
        lo++; hi++;
    }
    v.push_back(a[hi]);
    for (int i = lo; i < n - 1 - x; i++) v.push_back(a[i]);
    for (int i = 0; i < x; i++) {
        int pos = 2 * i + 1;
        if (!(v[pos - 1] > v[pos] && v[pos] < v[pos + 1])) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    check(lo);
    cout << lo << '\n';
    for (auto x : v) cout << x << " ";;
    return 0;
}