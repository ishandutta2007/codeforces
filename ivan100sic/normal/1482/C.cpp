// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll n, m, a, d, t[100005];

void step_many(ll& next_close, ll& sol, ll first_enter, ll period, ll to_enter) {
    if (next_close >= first_enter) {
        ll entered = min(to_enter, (next_close - first_enter) / period + 1);
        to_enter -= entered;
        first_enter += entered * period;
    }

    // the door is now closed
    ll cycle_people = d / period + 1;
    ll num_cycles = to_enter / cycle_people;

    // long cycles
    if (num_cycles > 0) {
        sol += num_cycles;
        to_enter -= cycle_people * num_cycles;
        first_enter += cycle_people * num_cycles * period;
        next_close = first_enter - period * cycle_people + d;
    }

    // final chunk
    if (to_enter > 0) {
        sol += 1;
        next_close = first_enter + d;
    }
}

void semi_brute() {
    vector<ll> v(t, t+m);
    for (int i : ra(1, n+1)) {
        v.push_back(a*i);
    }

    R::sort(v);
    ll next_close = -1, sol = 0;
    for (ll x : v) {
        step_many(next_close, sol, x, 1, 1);
        cerr << "after " << x << ' ' << sol << ' ' << sol << ' ' << next_close << '\n';
    }

    cerr << "sol = " << sol << '\n';
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> a >> d;
    for (int i : ra(0, m)) cin >> t[i];

    // semi_brute();

    ll next_close = -1, sol = 0, employees = 0;
    for (int i : ra(0, m)) {
        // run to < t[i]
        ll emp_tgt = min(n, t[i] / a);
        ll new_employees = emp_tgt - employees;

        step_many(next_close, sol, (employees + 1) * a, a, new_employees);
        employees += new_employees;
        step_many(next_close, sol, t[i], 1, 1);
    }

    if (employees != n) {
        ll new_employees = n - employees;
        step_many(next_close, sol, (employees + 1) * a, a, new_employees);
    }

    cout << sol << '\n';
}