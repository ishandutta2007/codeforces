#include <bits/stdc++.h>
using namespace std;

int steps = 0;
long long L, R, n;
int k;


bool ask(long long x, long long y) {
    cout << x << " " << y << endl;//<< " (" << L << " " << R << ")" << endl;
    steps++;
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n >> k;

    L = 1;
    R = n; // between L and R is it

    while (steps < 4500) {
        while (R - L > 45) {
            long long M = (L + R) / 2;
            bool found = ask(L, M);
            if (found) {
                R = M;
            } else {
                L = M + 1;
            }
            L = max(1LL, L - k);
            R = min(n, R + k);
        }

        long long x = uniform_int_distribution<long long>(L, R)(rng);
        if (ask(x, x))
            return 0;
        L = max(1LL, L - k);
        R = min(n, R + k);
    }
}