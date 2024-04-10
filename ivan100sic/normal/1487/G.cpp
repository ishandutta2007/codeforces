// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

int n;
int c[26];

mint dp[2][405][405][3][3];
mint sm[405][405];
mint si[405];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<26; i++) cin >> c[i];

    dp[0][0][0][0][0] = 1;
    for (int i=0; i<n; i++) {
        auto ol = dp[i % 2];
        auto nu = dp[1 - i % 2];
        memset(nu, 0, sizeof(dp[0]));

        for (int j=0; j<=i; j++) {
            for (int k=0; j+k<=i; k++) {
                for (int pl : {0, 1, 2}) {
                    for (int ql : {0, 1, 2}) {
                        for (int rl : {0, 1, 2}) {
                            int j2 = j + (rl == 0);
                            int k2 = k + (rl == 1);

                            mint coef = rl == 2 ? 24 : 1;
                            if (rl == pl && i >= 2) coef -= 1;

                            nu[j2][k2][ql][rl] += ol[j][k][pl][ql] * coef;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            for (int p : {0, 1, 2}) {
                for (int q : {0, 1, 2}) {
                    mint z = dp[n % 2][i][j][p][q];
                    sm[i][j] += z;
                    si[i] += z;
                }
            }
        }
    }

    // Svi lepi nizovi, bez obzira na ogranicenje c
    mint sol = (mint(25) ^ (n - 2)) * 26 * 26;

    // Bar jedno slovo preliva
    for (int i=0; i<26; i++) {
        for (int j=c[i]+1; j<=n; j++) {
            sol -= si[j];
        }
    }

    // Tacno dva slova prelivaju. Ovo smo malocas izbacili dvaput pa sad treba da vratimo jednom
    for (int i=0; i<26; i++) {
        for (int j=i+1; j<26; j++) {
            for (int p=c[i]+1; p<=n; p++) {
                for (int q=c[j]+1; q<=n; q++) {
                    sol += sm[p][q];
                }
            }
        }
    }

    cout << sol() << '\n';
}