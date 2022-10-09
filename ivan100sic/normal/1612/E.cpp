// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using namespace chrono;
struct stopwatch {
    typedef time_point<high_resolution_clock> tp;
    tp last_tick;
    bool notock;
    stopwatch() : notock(false) { tick(); }
    stopwatch(int) : notock(true) { tick(); }
    ~stopwatch() { if (!notock) tock(); }

    void tick() {
        last_tick = high_resolution_clock::now();
    }

    void tock() const {
        duration<double> dur = high_resolution_clock::now() - last_tick;
        cerr << "Time (s): " << dur.count() << '\n';
    }
};

// idk what the limit is so i'll do this

struct student {
    int m, k;
};

const ll LCM = 232792560;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<student> a(n);
    for (int i=0; i<n; i++) {
        int m, k;
        cin >> m >> k;
        a[i] = {m, k};
    }

    ll best_val = -1;
    vector<int> best_sol;

    auto t1 = high_resolution_clock::now();
    int w = 1;
    while (w < 200000) {
        auto t2 = high_resolution_clock::now();
        duration<double> dur = t2 - t1;
        if (dur.count() > 2.5) break;

        vector<pair<ll, int>> msg_score(200005);
        for (int i : ra(0, 200005)) {
            msg_score[i].second = i;
        }

        for (int i : ra(0, n)) {
            ll d = a[i].k >= w ? LCM : a[i].k * LCM / w;
            msg_score[a[i].m].first += d;
        }

        nth_element(msg_score.begin(), msg_score.begin() + w, msg_score.end(), greater<pair<ll, int>>());

        ll val = 0;
        for (int i : ra(0, w)) {
            val += msg_score[i].first;
        }

        if (val > best_val) {
            best_val = val;
            best_sol.resize(w);
            for (int i : ra(0, w)) {
                best_sol[i] = msg_score[i].second;
            }
        }

        w++;
    }

#ifdef LOCAL
    cout << w << '\n';
#endif

    cout << best_sol.size() << '\n';
    for (int x : best_sol) {
        cout << x << ' ';
    }
    cout << '\n';
}