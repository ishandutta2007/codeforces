#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 n, a, b, t;

struct event {
    int64 t, typ, info;
    bool operator>(const event &rhs) const {
        if (t != rhs.t) return t > rhs.t;
        return typ > rhs.typ;
    }
};

multiset<int64> Cu;
multiset<int64> presee;

priority_queue<event, vector<event>, greater<event> > Q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> t;
        if (b - a < t) continue;
        presee.insert(a + t);
        Q.push((event){a, 0, t});
        Q.push((event){b - t + 1, 1, t});
    }
    Q.push((event){0, 2, 0});
    int64 ans = 0;
    while (!Q.empty()) {
        event cc = Q.top();
        Q.pop();
        if (cc.typ == 0) {
            presee.erase(presee.find(cc.t + cc.info));
            Cu.insert(cc.info);
        }
        if (cc.typ == 1) {
            Cu.erase(Cu.find(cc.info));
        }
        if (cc.typ == 2) {
            if (!Cu.size()) {
                if (!presee.size()) {
                    continue;
                } else {
                    int64 nx = *presee.begin();
                    ans = ans + 1;
                    Q.push((event){nx, 2, 0});
                }
            } else {
                int64 mi = *Cu.begin() + cc.t;
                int64 req = mi - cc.t;
                if (presee.size() && *presee.begin() < mi) {
                    ans = ans + 1;
                    Q.push((event){*presee.begin(), 2, 0});
                    continue;
                } else {
                    event nxte = Q.top();
                    int64 cyct = max(1ll, (nxte.t - cc.t) / req);
                    ans += cyct;
                    Q.push((event){cc.t + cyct * req, 2, 0});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}