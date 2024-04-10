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


vector<ll> solve(vector<ll> s, vector<ll> l, vector<ll> r) {
    int n = s.size();
    int q = l.size();

    sort(s.begin(), s.end());

    vector<ll> a(n - 1);
    for (int i = 0; i < n - 1; i++) a[i] = s[i + 1] - s[i];
    sort(a.begin(), a.end());


    vector<ll> pref(n);
    for (int i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans;
    for (int i = 0; i < q; i++) {
        ll len = r[i] - l[i];
        int j = upper_bound(a.begin(), a.end(), len) - a.begin();

        ll res = 0;
        res += pref[j];
        res += (n - j) * (len + 1);

        ans.push_back(res);
    }
    return ans;
}

void print(vector<ll> a) {
    for (int i = 0; i < (int)a.size(); i++) printf("%lld%c", a[i], " \n"[i + 1 == (int)a.size()]);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<ll> s(n);
        for (int i = 0; i < n; i++) scanf("%lld", &s[i]);

        int q;
        scanf("%d", &q);
        vector<ll> l(q), r(q);
        for (int i = 0; i < q; i++) {
            scanf("%lld%lld", &l[i], &r[i]);
        }

        print(solve(s, l, r));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}