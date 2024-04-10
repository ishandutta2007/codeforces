#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const int N = 1.01e6;

vector<int> prefix(string s) {
    int n = s.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        while (p[i] && s[i] != s[p[i]]) p[i] = p[p[i] - 1];
        p[i] += s[i] == s[p[i]];
    }
    return p;
}

string solve(string a, string b) {
    int n = a.length(), m = b.length();

    if (m > n) return a;
    int cnta = 0, cntb = 0;
    for (char c : a) cnta += c - '0';
    for (char c : b) cntb += c - '0';
    if (cnta < cntb) return a;

    auto p = prefix(b);

    int per = m - p[m - 1];

    string res = b;
    cnta -= cntb;
    for (int i = m; i < n; i++) {
        if (cnta > 0) {
            res += res[i - per];
            cnta -= res.back() == '1';
        } else res += '0';
    }
    for (int i = n - 1; i >= 0; i--) {
        if (cnta > 0 && res[i] == '0') {
            res[i] = '1';
            cnta--;
        }
    }
    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    static char bufa[N], bufb[N];
    while (scanf("%s%s", bufa, bufb) == 2) {
        cout << solve(bufa, bufb) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}