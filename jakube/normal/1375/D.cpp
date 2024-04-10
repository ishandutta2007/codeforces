#include "bits/stdc++.h"
using namespace std;

// using ModInt = Modular<1'000'000'007>;

vector<bool> seen;

int mex(vector<int>& v, int n) {
    fill(seen.begin(), seen.end(), false);
    for (int x : v) {
        if (x < n)
            seen[x] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!seen[i])
            return i;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    int correct = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == i)
            correct++;
    }

    vector<int> steps;
    seen.resize(n);
    while (correct < n) {
        int m = mex(v, n);
        int idx = m;
        if (m == n) {
            for (int i = 0; i < n; i++) {
                if (v[i] != i)
                    idx = i;
            }
        }
        v[idx] = m;
        steps.push_back(idx);
        if (m < n)
            correct++;
    }
        
    cout << steps.size() << '\n';
    for (int x : steps)
        cout << x + 1 << ' ';
    cout << endl;
    
    assert(steps.size() <= 2 * n);
    for (int i = 0; i < n - 1; i++) {
        assert(v[i] < v[i+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}