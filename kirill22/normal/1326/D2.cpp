#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1000001, p = 2, MOD = 1e9 + 7, p2 = 101, MOD2 = 1e9 + 9;

vector<int> Pow(MAXN, 1);
vector<int> Pow2(MAXN, 1);

struct HASH {
    int n;
    vector<int> A;
    vector<int> B;
    HASH(string &a) : n((int) a.size()) {
        A.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            A[i] = ((A[i - 1] * p + a[i - 1]) % MOD);
        }
        B.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            B[i] = ((B[i - 1] * p2 + a[i - 1]) % MOD2);
        }
    }
    HASH() : n(0) {};
    int get(int l, int r) {
        return (A[r + 1] - A[l] * Pow[r - l + 1] + MOD * MOD) % MOD;
    }
    int get2(int l, int r) {
        return (B[r + 1] - B[l] * Pow2[r - l + 1] + MOD2 * MOD2) % MOD2;
    }
    int get1(int l, int r) {
        return get(l, r) * MOD2 + get2(l, r);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < MAXN; i++) {
        Pow[i] = (Pow[i - 1] * p) % MOD;
    }
    for (int i = 1; i < MAXN; i++) {
        Pow2[i] = (Pow2[i - 1] * p2) % MOD2;
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size();
        string ans = "";
        int l = 0;
        while (l < n -l - 1 && s[l] == s[n - l - 1]) {
            l++;
        }
        string b = s.substr(0, l);
        if (l > n - l - 1) {
            ans += b;
            reverse(b.begin(), b.end());
            ans += b;
            cout << ans << endl;
            continue;
        }
        s = s.substr(l, n - 2 * l);
        n = s.size();
        HASH A = HASH(s);
        reverse(s.begin(), s.end());
        HASH B = HASH(s);
        l = 0;
        int  r = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n - i - 1) {
                if (A.get1(0, i) == B.get1(n - 2 * i - 1, n - i - 1)) {
                    if (i * 2 + 1 > r - l + 1) {
                        l = 0, r = 2 * i;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n - i - 1) {
                if (B.get1(0, i) == A.get1(n - 2 * i - 1, n - i - 1)) {
                    if (i * 2 + 1 > r - l + 1) {
                        l = n - 2 * i - 1, r = n - 1;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (i <= n - i) {
                if (A.get1(0, i - 1) == B.get1(n - (2 * i - 1) - 1, n - i - 1)) {
                    if (i * 2 > r - l + 1) {
                        l = 0, r = 2 * i - 1;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (i <= n - i) {
                if (B.get1(0, i - 1) == A.get1(n - (2 * i - 1) - 1, n - i - 1)) {
                    if (i * 2 > r - l + 1) {
                        l = n - (2 * i - 1) - 1, r = n - 1;
                    }
                }
            }
        }
        ans += b;
        reverse(s.begin(), s.end());
        for (int i = l; i <= r; i++) ans += s[i];
        reverse(b.begin(), b.end());
        ans += b;
        cout << ans << endl;
    }
}