#include <bits/stdc++.h>

using namespace std;

int maxw = 5e5 + 100;
vector< vector<int> > divisors(maxw, vector<int>());

void inc_div(vector<int> &frequency, int x, int d) {
    int sz = divisors[x].size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        int number = 1;
        for (int i = 0; i < sz; i++) {
            if (mask & (1 << i)) {
                number *= divisors[x][i];
            }
        }
        frequency[number] += d;
    }
}

int get_change(vector<int> &frequency, int x) {
    int result = 0;
    int sz = divisors[x].size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        int number = 1, sign = 1;
        for (int i = 0; i < sz; i++) {
            if (mask & (1 << i)) {
                number *= divisors[x][i];
                sign = -sign;
            }
        }
        result += frequency[number] * sign;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = 2; i < maxw; i++) {
        if (divisors[i].empty()) {
            for (int j = i; j < maxw; j += i) {
                divisors[j].push_back(i);
            }
        }
    }

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long result = 0;
    vector<int> used(n + 1, 0);
    vector<int> frequency(maxw, 0);
    for (int times = 0; times < q; times++) {
        int x;
        cin >> x;

        if (used[x]) {
            inc_div(frequency, a[x], -1);
            result -= get_change(frequency, a[x]);
        } else {
            result += get_change(frequency, a[x]);
            inc_div(frequency, a[x], 1);
        }
        used[x] ^= 1;

        cout << result << '\n';
    }
}