// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[55];

struct seg {
    int l, r;
};

void primeni(const vector<int>& b) {
    int r = 0;
    for (int x : b) {
        reverse(a+r, a+r+x);
        r += x;
    }
    reverse(a, a+n);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> sol;

    while (1) {
        // podeli u blokove
        vector<seg> b;
        for (int i=0; i<n; i++) {
            if (b.size() && a[i] == a[i-1] + 1) {
                b.back().r++;
            } else {
                b.push_back({i, i+1});
            }
        }

        int m = b.size(), ii = -1, jj = -1;
        for (int i=0; i<m; i++) {
            for (int j=i+1; j<m; j++) {
                if (a[b[i].l] == a[b[j].r-1]+1) {
                    ii = i;
                    jj = j;
                }
            }
        }

        if (ii == -1) {
            break;
        }

        // seci
        vector<int> s;
        s.push_back(b[ii].l);
        s.push_back(b[jj].l - b[ii].l);
        s.push_back(b[jj].r - b[jj].l);
        s.push_back(n - b[jj].r);

        s.erase(remove_if(s.begin(), s.end(), [](int x) { return x == 0; }), s.end());
        primeni(s);
        sol.push_back(s);
    }

    cout << sol.size() << '\n';
    for (auto& v : sol) {
        cout << v.size();
        for (int x : v) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}