#include <bits/stdc++.h>
using namespace std;


template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<998'244'353>;

int convert(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 26;
    return 52 + (c - '0');
}

const int SZ = 62;
ModInt cnt[SZ][SZ];
ModInt dp[SZ][SZ][SZ];

const array<int, 5> fact = {1, 1, 2, 2*3, 2*3*4};

int number_of_perm(array<int, 4> arr) {
    int perm = fact[4];
    int cur = 0;
    while (cur < 4) {
        int i = cur + 1;
        while (i < 4 && arr[cur] == arr[i])
            i++;
        perm /= fact[i - cur];
        cur = i;
    }
    return perm;
}

ModInt solve(vector<string> v) {
    set<string> words;
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            cnt[i][j] = 0;
        }
    }
    for (string s : v) {
        int a = convert(s[0]);
        int b = convert(s.back());
        if (!words.count(s)) {
            cnt[a][b] += 1;
            words.insert(s);
        }
        reverse(s.begin(), s.end());
        if (!words.count(s)) {
            cnt[b][a] += 1;
            words.insert(s);
        }
    }

    for (int i = 0; i < SZ; i++) {
        for (int j = i; j < SZ; j++) {
            for (int k = j; k < SZ; k++) {
                dp[i][j][k] = 0;
                for (int mid = 0; mid < SZ; mid++) {
                    dp[i][j][k] += cnt[i][mid] * cnt[j][mid] * cnt[k][mid];
                }
            }
        }
    }

    //    .---i
    //   /   /|
    //  j---. |
    //  | l | .
    //  |   |/
    //  .---k
    ModInt result;
    for (int i = 0; i < SZ; i++) {
        for (int j = i; j < SZ; j++) {
            for (int k = j; k < SZ; k++) {
                for (int l = k; l < SZ; l++) {
                    result += dp[i][j][k] *
                              dp[i][j][l] *
                              dp[i][k][l] *
                              dp[j][k][l] *
                              number_of_perm({i, j, k, l});
                }
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<string>> words(11);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        words[s.size()].push_back(s);
    }
    ModInt result;
    for (int i = 3; i < 11; i++) {
        result += solve(words[i]);
    }
    cout << result << '\n';
}