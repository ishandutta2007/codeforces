#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> a, int j) {
    if ((int) a.size() <= 2) {
        return (int) a.size();
    }
    vector<int> l, r;
    for (auto x : a) {
        if (x >> j & 1) {
            l.push_back(x);
        } else {
            r.push_back(x);
        }
    }
    int resl = solve(l, j - 1) + ((int) r.size() > 0);
    int resr = solve(r, j - 1) + ((int) l.size() > 0);
    return max(resl, resr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << n - solve(a, 29);
}