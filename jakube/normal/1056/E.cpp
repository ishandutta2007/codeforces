#include <bits/stdc++.h>
using namespace std;

template <int C>
class Hashing {
public:
    Hashing(std::string const& s, array<std::pair<int, int>, C> pm) {
        n = s.size();
        for (int c = 0; c < C; c++) {
            int p = pm[c].first;
            m[c] = pm[c].second;
            p_pow[c].assign(n, 0);
            p_pow[c][0] = 1;
            for (int i = 1; i < n; i++) {
                p_pow[c][i] = (p_pow[c][i - 1] * p) % m[c];
            }

            h[c].assign(n + 1, 0);
            for (int i = 0; i < n; i++) {
                h[c][i + 1] = (h[c][i] + (s[i] - 'a' + 1) * p_pow[c][i]) % m[c];
            }
        }
    }

    std::array<int, C> hash(int i, int l) const {
        std::array<int, C> hashes;
        for (int c = 0; c < C; c++) {
            long long cur_h = (h[c][i + l] + m[c] - h[c][i]) % m[c];
            hashes[c] = cur_h * p_pow[c][n - i - 1] % m[c];
        }
        return hashes;
    }

    std::array<int, C> default_values() const {
        std::array<int, C> arr;
        std::fill(arr.begin(), arr.end(), -1);
        return arr;
    }

    int n;
    array<vector<long long>, C> p_pow;
    array<vector<long long>, C> h;
    std::array<int, C> m;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    if (s[0] == '0') {
        for (auto& c : s)
            c ^= 1;
    }

    array<int, 2> cnt{0, 0};
    for (char c : s) {
        cnt[c - '0']++;
    }


    Hashing<3> hash(t, {{{31, 1'000'000'007}, {37, 1'000'000'007}, {41, 900'000'011}}});
    int n = t.size();

    int result = 0;
    for (int a = 1; a * cnt[0] < n; a++) {
        int rem = n - a * cnt[0];
        if (rem % cnt[1] == 0) {
            int b = rem / cnt[1];

            // check
            int idx = 0;
            auto HA = hash.default_values();
            auto HB = hash.default_values();
            bool correct = true;
            for (char c : s) {
                int len = a;
                if (c == '1')
                    len = b;
                auto h = hash.hash(idx, len);

                if (c == '0') {
                    if (HA[0] == -1)
                        HA = h;
                    else
                        correct &= HA == h;
                } else {
                    if (HB[0] == -1)
                        HB = h;
                    else
                        correct &= HB == h;
                }
                idx += len;
            }
            if (correct && (HA != HB))
                result++;
        }
    }
    cout << result << '\n';
}