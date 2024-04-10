#include <bits/stdc++.h>
using namespace std;

struct S
{
    int s, d, c;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<S> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i].s >> x[i].d >> x[i].c;
        x[i].s--;
        x[i].d--;
        x[i].idx = i+1;
    }

    vector<int> shedule(n);
    vector<S> cur;
    for (int day = 0; day < n; day++) {
        for (auto y : x) {
            if (y.s == day) {
                cur.push_back(y);
            }
        }

        // check if exam today
        bool exam = false;
        for (auto& y : cur) {
            if (y.d == day) {
                if (y.c || exam) {
                    cout << -1 << '\n';
                    return 0;
                }
                shedule[day] = m + 1;
                exam = true;
            }
        }

        if (!exam) {
            int best = -1;
            for (int i = 0; i < (int)cur.size(); i++) {
                auto& e = cur[i];
                if (e.d > day && e.c > 0 && (best == -1 || cur[best].d > e.d))
                    best = i;
            }
            if (best >= 0) {
                shedule[day] = cur[best].idx;
                cur[best].c--;
            } else {
                shedule[day] = 0;
            }
        }
    }

    bool check = true;
    for (auto& c : cur) {
        if (c.c > 0)
            check = false;
    }

    if (check) {
        for (auto x : shedule) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
        
    }
}