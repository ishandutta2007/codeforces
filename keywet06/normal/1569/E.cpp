#include <bits/stdc++.h>

const int P = 998244353;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int k, A, h;
    std::cin >> k >> A >> h;

    int N = 1 << k;

    std::vector<std::pair<int, int>> u1, u2;
    std::vector<std::pair<int, int>> v1, v2;

    int p[6];
    int score[k + 1];
    p[k] = 1;

    for (int i = 0; i < k; i++) {
        p[i] = 1 + (1 << (k - i - 1));
    }
    for (int i = 0; i <= k; i++) {
        score[i] = 1;
        for (int j = 0; j < p[i]; j++) {
            score[i] = 1LL * score[i] * A % P;
        }
    }

    for (int s = 0; s < (1 << (N / 2 - 1)); s++) {
        int winner = 0;
        int h0 = 0, h1 = 0;
        for (int i = 0; i < N / 2; i++) {
            int j;
            for (j = 0; j < k - 1; j++) {
                if ((i >> j & 1) !=
                    (s >> (N / 2 - 1 - (i >> (j + 1)) - (1 << (k - j - 2))) &
                     1)) {
                    break;
                }
            }
            if (j == k - 1) {
                winner = i;
            } else {
                h0 = (h0 + 1LL * (i + 1) * score[j]) % P;
                h1 = (h1 + 1LL * (i + 1 + N / 2) * score[j]) % P;
            }
        }
        u1.emplace_back((h0 + 1LL * (winner + 1) * score[k]) % P, s);
        u2.emplace_back((h0 + 1LL * (winner + 1) * score[k - 1]) % P, s);
        v1.emplace_back((h1 + 1LL * (winner + 1 + N / 2) * score[k]) % P, s);
        v2.emplace_back((h1 + 1LL * (winner + 1 + N / 2) * score[k - 1]) % P,
                        s);
    }

    std::sort(u1.begin(), u1.end());
    std::sort(u2.begin(), u2.end());
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    auto work = [&](auto u, auto v, int t) {
        for (auto [x, s0] : u) {
            int y = (h - x + P) % P;
            auto it =
                std::lower_bound(v.begin(), v.end(), std::make_pair(y, 0));
            if (it == v.end() || it->first != y) {
                continue;
            }
            int s1 = it->second;

            int res[N];

            int winner0 = 0;
            int winner1 = 0;
            for (int i = 0; i < N / 2; i++) {
                int j;
                for (j = 0; j < k - 1; j++) {
                    if ((i >> j & 1) != (s0 >> (N / 2 - 1 - (i >> (j + 1)) -
                                                (1 << (k - j - 2))) &
                                         1)) {
                        break;
                    }
                }
                if (j == k - 1) {
                    winner0 = i;
                } else {
                    res[i] = p[j];
                }
                for (j = 0; j < k - 1; j++) {
                    if ((i >> j & 1) != (s1 >> (N / 2 - 1 - (i >> (j + 1)) -
                                                (1 << (k - j - 2))) &
                                         1)) {
                        break;
                    }
                }
                if (j == k - 1) {
                    winner1 = i + N / 2;
                } else {
                    res[i + N / 2] = p[j];
                }
            }

            if (t == 0) {
                res[winner0] = 1;
                res[winner1] = 2;
            } else {
                res[winner0] = 2;
                res[winner1] = 1;
            }

            for (int i = 0; i < N; i++) {
                std::cout << res[i] << " \n"[i == N - 1];
            }
            std::exit(0);
        }
    };

    work(u1, v2, 0);
    work(u2, v1, 1);

    std::cout << "-1\n";

    return 0;
}