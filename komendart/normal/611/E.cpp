#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    multiset<int> t;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        t.insert(v);
    }

    vector<int> vabc = {a, b, c}; sort(vabc.begin(), vabc.end());
    a = vabc[0]; b = vabc[1]; c = vabc[2];

    if (*t.rbegin() > a + b + c) {
        cout << "-1\n";
        return 0;
    }

    int res = 0;
    while (!t.empty() && *t.rbegin() > b + c) {
        t.erase(t.find(*t.rbegin()));
        res++;
    }
    while (!t.empty() && *t.rbegin() > a + c) {
        t.erase(t.find(*t.rbegin()));
        auto it = t.upper_bound(a);
        if (!t.empty() && it != t.begin()) {
            it--;
            t.erase(it);
        }
        res++;
    }
    /*cerr << t.size() << endl;*/
    while (!t.empty() && *t.rbegin() > max(a + b, c)) {
        t.erase(t.find(*t.rbegin()));
        auto it = t.upper_bound(b);
        if (!t.empty() && it != t.begin()) {
            it--;
            t.erase(it);
        }
        res++;
    }
    //maximal <= max(a + b, c)
    while (!t.empty() && *t.rbegin() > c) {
        t.erase(t.find(*t.rbegin()));
        auto it = t.upper_bound(c);
        if (!t.empty() && it != t.begin()) {
            it--;
            t.erase(it);
        }
        res++;
    }
    //maximal <= c
    /*cerr << res << endl;
    for (auto i: t) cerr << i << ' '; cerr << endl;*/
    while (!t.empty()) {
        res++;
        t.erase(t.find(*t.rbegin()));
        if (t.empty()) break;
        if (*t.begin() > a + b) continue;
        if (t.size() == 1) {
            break;
        }
        auto it = t.upper_bound(b);
        bool flag = (it != t.begin());
        if (flag) it--;
        if (flag && it != t.begin() && *t.begin() <= a) {
            t.erase(it);
            it = t.upper_bound(a);
            it--;
            t.erase(it);
        } else {
            it = t.upper_bound(a + b);
            it--;
            t.erase(it);
        }
    }

    cout << res << '\n';
}