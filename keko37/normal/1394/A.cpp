#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint n, d, m, sol;
llint a[MAXN], p[MAXN];
vector <llint> lo, hi, v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= m) {
            sol += a[i];
            lo.push_back(a[i]);
        } else {
            hi.push_back(a[i]);
        }
    }
    sort(lo.begin(), lo.end());
    sort(hi.begin(), hi.end());
    reverse(lo.begin(), lo.end());
    for (auto x : lo) v.push_back(x);
    for (auto x : hi) v.push_back(x);
    for (int i = 0; i < n; i++) {
        if (v[i] <= m) p[i] = v[i];
        if (i > 0) p[i] += p[i - 1];
    }
    llint big = 0;
    for (int i = 0; i < hi.size(); i++) {
        big += hi[(int)hi.size() - 1 - i];
        int ost = (int)hi.size() - 1 - i + lo.size();
        if (ost < i * d) break;
        int ind = n - 1 - i * (d + 1);
        if (ind < 0) break;
        llint val = big;
        if (ind - 1 >= 0) val += p[ind - 1];
        sol = max(sol, val);
    }
    cout << sol;
    return 0;
}