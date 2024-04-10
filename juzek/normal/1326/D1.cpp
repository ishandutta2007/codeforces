#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

string rozwal(string s) {
    int n = s.size();
    vector<int> d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) ++k;
        d1[i] = k;
        if (i + k - 1 > r)
            l = i - k + 1, r = i + k - 1;
    }
    vector<int> d2(n);
    l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) ++k;
        d2[i] = k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    int spoko = 0;
    int pocz = 0, kon = n - 1;
    while (pocz < kon && s[pocz] == s[kon]) {
        pocz++, kon--;
        spoko++;
    }
    int wyn = 0;
    int koniec = (n + 1) / 2;
    bool kk = n % 2 == 0;
    for (int i = 0; i <= koniec; i++) {
        if (i != koniec && i - d1[i] + 1 <= spoko)
            wyn = max(wyn, (i - d1[i] + 1) * 2 + d1[i] * 2 - 1);
        if ((i != koniec || kk) && i - d2[i] <= spoko)
            wyn = max(wyn, (i - d2[i]) * 2 + d2[i] * 2);
    }
    for (int i = 0; i <= koniec; i++) {
        if (i != koniec && i - d1[i] + 1 <= spoko && (i - d1[i] + 1) * 2 + d1[i] * 2 - 1 == wyn) {
            string ret = "";
            for (int w = 0; w < i + d1[i]; w++)
                ret += s[w];
            for (int w = n - (i - d1[i] + 1); w < n; w++)
                ret += s[w];
            return ret;
        }
        if ((i != koniec || kk) && i - d2[i] <= spoko && (i - d2[i]) * 2 + d2[i] * 2 == wyn) {
            string ret = "";
            for (int w = 0; w < i + d2[i]; w++)
                ret += s[w];
            for (int w = n - (i - d2[i]); w < n; w++)
                ret += s[w];
            return ret;
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string a = rozwal(s);
        reverse(s.begin(), s.end());
        string b = rozwal(s);
        if (a.size() > b.size())
            cout << a << "\n";
        else
            cout << b << "\n";
    }
    return 0;
}