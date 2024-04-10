#include <bits/stdc++.h>
using namespace std;

struct Customer {
    long long t, l, h;
};

string solve() {
    int n, m;
    cin >> n >> m;
    vector<Customer> customers(n);
    for (auto& x : customers)
        cin >> x.t >> x.l >> x.h;

    long long L = m, H = m;
    int t = 0;
    for (auto customer : customers) {
        int dur = customer.t - t;
        L -= dur;
        H += dur;
        L = max(L, customer.l);
        H = min(H, customer.h);
        if (L > customer.h || H < customer.l)
            return "NO";

        t = customer.t;
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << solve() << '\n';
    }
}