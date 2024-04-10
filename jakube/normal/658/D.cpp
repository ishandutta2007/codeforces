#include <bits/stdc++.h>
using namespace std;

vector<int> to_bits(vector<int> v, int n) {
    vector<int> bits(n + 50, 0);
    for (int i = 0; i < n + 1; i++) {
        int val = v[i];
        bool negative = val < 0;
        val = abs(val);
        int j = i;
        while (val) {
            if (val & 1) {
                if (negative)
                    bits[j]--;
                else
                    bits[j]++;
            }
            val >>= 1;
            j++;
        }
    }

    int next = 0;
    for (auto& b : bits) {
        b += next;
        if ((b & 1) == 0) {
            next = b / 2;
            b = 0;
        } else {
            next = (b - 1) / 2;
            b = 1;
        }
    }

    return bits;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> v[i];
    }
    
    auto bits = to_bits(v, n);
    if (bits.back()) {
        // negative = bad
        for (auto& val : v)
            val *= -1;
        bits = to_bits(v, n);
    }

    // find first set bit
    int idx = 0;
    while (bits[idx] == 0)
        idx++;

    // compute value which we have to delete
    long long val = 0;
    long long base = 1;
    for (int i = idx; i < (int)bits.size(); i++) {
        val += base * bits[i];
        base *= 2;
        if (val > 4 * k || (bits[i] && i - idx > 40)) {
            cout << 0 << '\n';
            return 0;
        }
    }

    // count the ways
    int cnt = 0;
    while (val < 4 * k && idx >= 0) {
        long long neww = v[idx] - val;
        if (abs(neww) <= k && (idx < n || (idx == n && neww != 0)))
            cnt++;
        val *= 2;
        idx--;
    }
    cout << cnt << '\n';
}