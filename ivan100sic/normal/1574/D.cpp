// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using build = array<int, 10>;

int n, m;
vector<int> a[10];
set<build> s;

int val(build b) {
    int x = 0;
    for (int i=0; i<n; i++) {
        x += a[i][b[i]];
    }
    return x;
}

build empty() {
    build b;
    fill(begin(b), end(b), 0);
    return b;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j=0; j<k; j++) cin >> a[i][j];        
    }
    
    cin >> m;
    for (int i=0; i<m; i++) {
        auto b = empty();
        for (int j=0; j<n; j++) cin >> b[j], b[j]--;
        s.insert(b);
    }

    auto base = empty();
    for (int j=0; j<n; j++) base[j] = a[j].size() - 1;
    int sol = 0;
    build ans;

    if (s.count(base)) {
        for (auto b : s) {
            for (int i=0; i<n; i++) {
                if (b[i]) {
                    auto b2 = b;
                    b2[i]--;
                    if (!s.count(b2)) {
                        int v2 = val(b2);
                        if (v2 > sol) {
                            sol = v2;
                            ans = b2;
                        }
                    }
                }  
            }
        }
    } else {
        ans = base;
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] + 1 << " \n"[i == n-1];
    }
}