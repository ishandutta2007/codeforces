#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, sol;
int a[MAXN];
vector <pi> v;
vector <int> r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n;) {
        int val = a[i], br = 0;
        for (; i < n && a[i] == val; i++) {
            br++;
        }
        v.push_back({val, br});
    }
    sol = v.size();
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second >= 2) {
            sol++;
            r.push_back(i);
        }
    }
    for (int i = 1; i < r.size(); i++) {
        int lo = r[i - 1], hi = r[i];
        if (v[lo].first != v[hi].first) continue;
        bool ok = 0;
        for (int j = lo + 1; j < hi; j++) {
            if (v[j].first != v[lo].first && v[j - 1].first != v[j + 1].first) {
                ok = 1;
                break;
            }
        }
        if (!ok) sol--;
    }
    cout << sol;
    return 0;
}